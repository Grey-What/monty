#include "monty.h"
/**
 * free_stack - frees adoubly linked list stack in reverse with top pointer
 *
 * @head: pointer to head of linked list/bottom of stack
 *
 * Return: void
 */
void free_stack(stack_t **head)
{
	stack_t *temp = NULL;

	while ((*head) != NULL)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
	free(*head);
}
