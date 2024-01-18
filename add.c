#include "monty.h"
/**
* add - adds the top two elements of the stack
* @stack: points to the stack
* Return: void
*/
void add(stack_t **stack, unsigned int line_number)
{
	int res = 0;

	if ((*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->n + ((*stack)->prev)->n;
	pop(stack, line_number);
	(*stack)->n = res;
}
