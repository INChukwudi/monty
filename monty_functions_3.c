#include "monty.h"

/**
 * monty_nop - does nothing
 * @stack: pointer to head of stack or tail of queue
 * @line_number: current line number being executed
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pint - prints first elements of the stack or queue
 * @stack: pointer ot head of stack or tail of queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !(*stack))
	{
		pint_error(line_number);
		return;
	}
	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	printf("%d\n", tmp->n);
}
