#include "monty.h"
/**
* pall - prints value on stack , from the top.
*
* @stack: points to stack
* @line_number: line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);
	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
