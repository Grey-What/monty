#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
instruction_t func_match[4];

/**
 * struct container_s - store variables, value, file, opcode line
 *
 * @value: argument to op code
 * @opcode_command: monty command
 *
 * Description: carries values through program
 */
typedef struct container_s
{
	int value;
	char *opcode_command;
} container_t;
container_t container;

void match_opcode(stack_t **head, char *opcode_line, unsigned int line_number);
void free_list(char **list);
void getvalue(char *opcode_line, unsigned int line_number);
void free_stack(stack_t **stack);

void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
#endif
