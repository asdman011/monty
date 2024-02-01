#include "monty.h"
#define UNUSED __attribute__((unused))

/**
* freelist - free a doubly linked list
* @stack: head of stack
*
* Return: void
*/

void freelist(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(stack);
}

/**
 * whitespace_check - checks if str is all whitespace
 * @str: string to check
 *
 * Return: -1 if not whitespace or 0 if is whitespace
 */

int whitespace_check(char *str)
{
	int c, d;

	for (c = 0; str[c]; c++)
	{
		if (isspace(str[c]) == 0)
		{
			d = -1;
			return (d);
		}
	}
	d = 0;
	return (d);
}
/**
* mod - opcode function
* @stack: stack given to subtract
* @line_number: line number for error
*
* Description: opcode function to subtract top two values together
* Return: 0 success
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	if (val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	temp->n = temp->n % val;
	free(*stack);
	temp->prev = NULL;
	*stack = temp;
}
/**
* comments - function
* @stack: stack given
* @line_number: line_number for error
*
* Description: function to do nothing(comments)
* Return: nothing
*/
void comments(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
}
