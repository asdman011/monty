#include "monty.h"
char *num = NULL;
/**
* main - main function of monty interpreter
* @argv: list of arguments
* @argc: argument count
*
* Return: nothing
*/

int main(int argc, char *argv[])
{
	FILE *rmonty;
	char *c, buff[1024];
	unsigned int line_number = 1;
	stack_t **stack = malloc(sizeof(stack_t *));
	*stack = NULL;

	if (stack == NULL)
	{fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{fprintf(stderr, "USAGE: monty file\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	rmonty = fopen(argv[1], "r");
	if (rmonty == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = fgets(buff, 255, (FILE *)rmonty);
		if (c == NULL)
			break;
		if (whitespace_check(c) != 0)
			parse(c, stack, line_number);
		line_number++;
	}
	freelist(stack);
	fclose(rmonty);
	return (0);
}

/**
* parse - function
* @c: char to check in string
* @stack: stack given to parse
* @line_number: line number for errors
*
* Description: function to tokenize string
* Return: 0 success
*/

void parse(char *c, stack_t **stack, unsigned int line_number)
{
	int i;
	char *delim = " ";
	char *tokens;

	instruction_t code[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"#", comments},
		{"NULL", NULL}
	};
	for (i = 0; c[i] != '\0'; i++)
	{
		if (c[i] == '\n')
		c[i] = '\0';
	}

	tokens = strtok(c, delim);
	num = strtok(NULL, delim);
	for (i = 0; i < 13; i++)
	{
		if (strcmp(code[i].opcode, tokens) == 0)
		{
			code[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens);
	if (*stack != NULL)
		freelist(stack);
	exit(EXIT_FAILURE);
}

