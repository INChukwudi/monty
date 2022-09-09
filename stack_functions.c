#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to the head of stack or tail of queue
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - initializes a stack
 * @stack: pointer to an empty stack
 *
 * Return: EXIT_FAILURE - an error occurs
 *         EXIT_SUCCESS - on success
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;
	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if a linked list is a stack or queue
 * @stack: pointer to the head of stack or tail of queue
 *
 * Return: 1 - if is a stack
 *         0 - otherwise
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
