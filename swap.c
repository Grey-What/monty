#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to top of stack
 * @line_number: line number of opcode
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!(*stack) || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->prev)->n;
	((*stack)->prev)->n = temp;
}
