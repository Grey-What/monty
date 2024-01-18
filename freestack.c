#include "monty.h"
/**
 * free_stack - frees adoubly linked list stack in reverse with top pointer
 *
 * @stack: pointer to top of stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	while ((*stack) != NULL)
	{
		temp = (*stack);
		(*stack) = (*stack)->prev;
		free(temp);
	}
	free(*stack);
}
