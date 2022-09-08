#include "monty.h"

/**
 * short_stack_error - prints error messages for monty math function
 * @line_number: line number of opcode being currently executed
 * @op: opcode
 *
 * Return: (EXIT_FAILURE)
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L<%u>: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - prints error message for monty_div function
 * @line_number: line number of opcode currently being executed
 *
 * Return: (EXIT_FAILUREi)
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pop_error - prints the error message for monty_pop
 * @line_number: line number of opcode currently being occured
 *
 * Return: (EXIT_FAILURE)
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints th error message for monty_pint
 * @line_number: line number of opcode currently being occured
 *
 * Return: (EXIT_FAILURE)
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
