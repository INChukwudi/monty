#include "monty.h"

/**
 * monty_add - adds the two top elements of a stack
 * @stack: pointer to the top of a stack or tail of a queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) ||
		(!((*stack)->prev) && !((*stack)->next)) ||
		(!((*stack)->next) && !((*stack)->prev)))
	{
		short_stack_error(line_number, "add");
		return;
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}

	tmp->next->n += tmp->n;
	tmp->next->prev = NULL;
	if (*stack == tmp)
		*stack = tmp->next;
	free(tmp);
}

/**
 * monty_sub - subtracts the head from 2nd element from the top
 * @stack: pointer to the top of stack or tail of queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) ||
		(!((*stack)->prev) && !((*stack)->next)) ||
		(!((*stack)->next) && !((*stack)->prev)))
	{
		short_stack_error(line_number, "sub");
		return;
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}

	tmp->next->n -= tmp->n;
	tmp->next->prev = NULL;
	if (*stack == tmp)
		*stack = tmp->next;
	free(tmp);
}

/**
 * monty_div - divides 2nd element from the head of a stack with the head
 * @stack: pointer to the head of stack or tail of queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) ||
		(!((*stack)->prev) && !((*stack)->next)) ||
		(!((*stack)->next) && !((*stack)->prev)))
	{
		short_stack_error(line_number, "div");
		return;
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}

	if (tmp->n == 0)
	{
		div_error(line_number);
		return;
	}

	tmp->next->n /= tmp->n;
	tmp->next->prev = NULL;
	if (*stack == tmp)
		*stack = tmp->next;
	free(tmp);
}

/**
 * monty_mul - multiplies 2nd element from the head of a stack with the head
 * @stack: pointer to the head of astack or tail of a queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) ||
		(!((*stack)->prev) && !((*stack)->next)) ||
		(!((*stack)->next) && !((*stack)->prev)))
	{
		short_stack_error(line_number, "mul");
		return;
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}

	tmp->next->n *= tmp->n;
	tmp->next->prev = NULL;
	if (*stack == tmp)
		*stack = tmp->next;
	free(tmp);
}

/**
 * monty_mod - comutes modulus of 2nd element from the head of a stack
 * @stack: pointer to the head of a stack or tail of a queue
 * @line_number: current line number being executed
 *
 * Return: void
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) ||
		(!((*stack)->prev) && !((*stack)->next)) ||
		(!((*stack)->next) && !((*stack)->prev)))
	{
		short_stack_error(line_number, "mod");
		return;
	}

	tmp = *stack;
	if ((*stack)->next == NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}

	if (tmp->n == 0)
	{
		div_error(line_number);
		return;
	}

	tmp->next->n %= tmp->n;
	tmp->next->prev = NULL;
	if (*stack == tmp)
		*stack = tmp->next;
	free(tmp);
}
