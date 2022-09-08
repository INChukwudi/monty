#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack/queue
 * @n: integer
 * @prev: pointer to the previous element on the stack/queue
 * @next: pointer to the next element on the stack/queue
 */ 
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int run_monty(FILE *script_fd);
void free_tokens(void);
void free_stack(stack_t **stack);

char **strtow(char *str, char *delim);

int usage_error(void);
int f_open_error(char *filename);
int malloc_error(void);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);

void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
