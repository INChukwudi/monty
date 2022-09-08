#include "monty.h"

/**
 * free_tokens - frees token
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks[i])
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);
	free(op_toks);
}

/**
 * free_stack - frees a stack from memory
 * @stack: pointer to head or tail of stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL, *iter = NULL;

	if (stack && *stack)
	{
		tmp = *stack;
		if ((*stack)->next == NULL)
		{
			while (tmp)
			{
				iter = tmp->prev;
				free(tmp);
				tmp = iter;
			}
		}
		else
		{
			while (tmp)
			{
				iter = tmp->next;
				free(tmp);
				tmp = iter;
			}
		}
	}
}

/**
 * get_op_func - match an opcode with the corresponding function
 * @opcode: opcode
 *
 * Return: pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"stack", monty_stack},
		{"queue", monty_queue},
		{"push", monty_push},
		{"pop", monty_pop},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"add", monty_add},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"nop", monty_nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_monty - function to execute a monty script
 * @script_fd: file descriptor for the script
 *
 * Return: (EXIT_SUCCESS) on success
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	void (*op_func)(stack_t**, unsigned int);
	int read = -1;

	while (getline(&line, &len, script_fd) != -1)
	{
		op_toks = strtow(line, " \n\t\a\b");
		if (op_toks == NULL)
		{
			free_stack(&stack);
			return (malloc_error());
		}
		if (op_toks[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_tokens();
			free_stack(&stack);
			return (unknown_op_error(op_toks[0], line_number));
		}
		op_func(&stack, line_number);
		line_number++;
		free_tokens();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (EXIT_SUCCESS);
}
