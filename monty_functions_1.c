#include "monty.h"

/**
 * monty_stack - converts a stack to a queue
 * @stack: pointer to the head or tail of a stack
 * @line_number: line number of the opcodes file currently executing
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	*stack = tmp;

	(void) line_number;
}

/**
 * monty_queue - converts a queue to a stack
 * @stack: pointer to head or tail of a stack
 * @line_number: line number of the opcodes file
 *
 * Return: void
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	*stack = tmp;
	(void) line_number;
}

/**
 * monty_pall - prints a stack
 * @stack: pointer to the head or tail of a stack
 * @line_number: line number of the opcodes file currently at
 *
 * Return: void
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		return;
	tmp = *stack;

	if (tmp->prev == NULL)
	{
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}

	(void) line_number;
}

/**
 * monty_push - pushes a value to the stack
 * @stack: pointer to the head or tail of a stack
 * @line_number: line number of the file the program is currently at
 *
 * Return: void
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int value;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_error();
		return;
	}
	if (op_toks[1] == NULL)
	{
		no_int_error(line_number);
		return;
	}
	value = atoi(op_toks[1]);
	if (value == 0 && *op_toks[1] != '0')
	{
		no_int_error(line_number);
		return;
	}
	new->n = value;
	if (!stack || !(*stack) || (*stack)->prev == NULL)
	{
		if (!stack || !(*stack))
			tmp = NULL;
		else
			tmp = *stack;
		new->prev = NULL;
		new->next = tmp;
		if (tmp != NULL)
			tmp->prev = new;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->prev)
			tmp = tmp->prev;
		new->prev = NULL;
		new->next = tmp;
		if (tmp != NULL)
			tmp->prev = new;
	}
}

/**
 * monty_pop - removes the head of stack or tail of queue
 * @stack: stack or queue to remove value from
 * @line_number: line number of the file that is executing
 *
 * Return: void
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL, *prev = NULL;

	if (!stack || !(*stack))
	{
		pop_error(line_number);
		return;
	}
	else if ((*stack)->prev != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		if (next)
			next->prev = NULL;
		*stack = next;
	}
	else
	{
		prev = (*stack)->prev;
		free(*stack);
		if (prev)
			prev->next = NULL;
		*stack = prev;
	}
}
