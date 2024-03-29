#include "monty.h"
/**
* pint - prints the value on top of the stack.
* @stack: pointer to the head of a linked list
* @line_number: line number
* Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
