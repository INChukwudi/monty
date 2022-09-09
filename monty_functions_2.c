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
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	tmp = (*stack)->next;
	tmp->next->n -= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	tmp = (*stack)->next;
	if (tmp->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	tmp->next->n /= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	tmp = (*stack)->next;
	tmp->next->n *= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
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

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	tmp = (*stack)->next;
	if (tmp->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	tmp->next->n %= tmp->n;
	tmp->next->prev = *stack;
	(*stack)->next = tmp->next;
	free(tmp);
}
