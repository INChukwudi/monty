#include "monty.h"

/**
 * pchar_error - prints error messages for monty_pchar function
 * @line_number: current line number being executed
 * @message: corresponding error message to print
 *
 * Return: (EXIT_FAILURE)
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
