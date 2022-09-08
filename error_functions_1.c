#include "monty.h"

/**
 * usage_error - prints usage error and returns error code
 *
 * Return: (EXIT_FAILURE)
 */
int usage_error(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 18);
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints usage error and returns error code
 * @filename: file name
 *
 * Return: (EXIT_FAILURE)
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file <%s>\n", filename);
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error info and returns error code
 *
 * Return: (EXIT_FAILURE)
 */
int malloc_error(void)
{
	write(STDERR_FILENO, "Error: malloc failed\n", 21);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - prints unknown opcode error to STDERR
 * @opcode: opcode where error occured
 * @line_number: line number in script where error occured
 *
 * Return: (EXIT_FAILURE)
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L<%u>: unknown instruction <%s>\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints the invalid argument provided error
 * @line_number: line in script where error occured
 *
 * Return: (EXIT_FAILURE)
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
