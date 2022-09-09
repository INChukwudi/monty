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
 * @stack: pointer to head of stack or tail of queue
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

/**
 * monty_pchar - pritns the charcater at the top of a linked list
 * @stack: pointer to head of stck or tail of queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
						"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_swap - swaps the top two elements of the stack
 * @stack: pointer to the head of stack or tail or queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * monty_pstr - prints the string contained in a stack or queue
 * @stack: pointer to the top of stack or tail of queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
	(void)line_number;
}
