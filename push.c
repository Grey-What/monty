#include "monty.h"
/**
 * push - creates new node in doubly linked list
 *
 * @stack: pointer to top of stack
 * @line_number: line number of current opcode
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = container.value;

	new->next = NULL;
	new->prev = (*stack);

	if ((*stack) != NULL)
		(*stack)->next = new;
	(*stack) = new;
}
