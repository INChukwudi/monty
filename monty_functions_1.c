#include "monty.h"

/**
 * monty_stack - converts a stack to a queue
 * @stack: pointer to the head or tail of a stack
 * @line_number: line number of the opcodes file currently executing
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
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
	(*stack)->n = QUEUE;
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
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
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
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->prev)
			tmp = tmp->prev;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
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
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}
	
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
