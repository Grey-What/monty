#include "monty.h"
/*
* pall - prints value on stack , from the top. 
* @stack: points to stack
* @line_number: line number
*/
void pall(stack_t **stack, unsigned int line_number);
{
	stack_t *s = *stack;
	(void)line_number;

	while (s != NULL)
	{
		print("%d/n", s->n);
		s = s->next;
	}		
}
