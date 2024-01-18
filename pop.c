#include "monty.h"
/**
* pop - removes the top element of stack
* @stack: pointer to the head of a linked list
* @line_number: line number
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->prev;
	free(temp);
}
