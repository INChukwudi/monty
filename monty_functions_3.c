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
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}
	printf("%d\n", (*stack)->next->n);
}
