#include "monty.h"
/**
 * push - creates new node in doubly linked list
 *
 * @head: pointer to doubly linked list
 * @line_number: line number of current opcode
 *
 * Return: void
 */
void push(stack_t **head, unsigned int line_number)
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
	new->prev = top;

	if (top != NULL)
		top->next = new;
	else
		*head = new;
	top = new;
}
