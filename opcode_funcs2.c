#include "monty.h"

/**
* add - opcode function
* @stack: stack given to add
* @line_number: line number for error
*
* Description: opcode function to add top two values
* Return: 0 success
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(*stack);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp = temp->next;
	temp->n = temp->n + val;
	free(*stack);
	temp->prev = NULL;
	*stack = temp;
}

/**
* push - opcode function
* @stack: stack given to add to
* @line_number: line number for error
*
* Description: function to add node to top of stack
* Return: 0 success
*/

void push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *push = malloc(sizeof(stack_t));

	if (push == NULL)
	{fprintf(stderr, "Error: malloc failed");
		freelist(stack);
		exit(EXIT_FAILURE); }
	if (num == NULL || isspace(num[0]) != 0)
	{fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(push);
		freelist(stack);
		exit(EXIT_FAILURE); }
	for (i = 0; num[i] != '\0'; i++)
	{
		if (isdigit(num[i]) == 0)
		{fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(push);
			freelist(stack);
			exit(EXIT_FAILURE);
		}
	}
	i = atoi(num);
	push->n = i;
	if (*stack == NULL)
	{
		*stack = push;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
	}
	else
	{
		(*stack)->prev = push;
		push->next = (*stack);
		(*stack) = push;
		push->prev = NULL;
	}
}
/**
* sub - opcode function
* @stack: stack given to subtract
* @line_number: line number for error
*
* Description: opcode function to subtract top two values together
* Return: 0 success
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freelist(stack);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp = temp->next;
	temp->n = temp->n - val;
	free(*stack);
	temp->prev = NULL;
	*stack = temp;
}
/**
* _div - opcode function
* @stack: stack given to divide
* @line_number: line number for error
*
* Description: opcode function to divide top two values
* Return: 0 success
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freelist(stack);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	if (val == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freelist(stack);
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	temp->n = val / temp->n;
	free(*stack);
	temp->prev = NULL;
	*stack = temp;
}
/**
* mul - function
* @stack: stack given
* @line_number: line_number for error
*
* Description: func to get product of top two from stack
* Return: 0 success
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int val;

	if (*stack == NULL)
		return;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		freelist(stack);
		exit(EXIT_FAILURE);
	}
	val = temp->n;
	temp = temp->next;
	temp->n = val * temp->n;
	free(*stack);
	temp->prev = NULL;
	*stack = temp;
}
