#include "monty.h"
/**
 * match_opcode - matching file line text to relevant function
 *
 * @stack: pointer to top of stack
 * @opcode_line: line of opcode retrieved from file
 * @line_nr: line number of opcode line
 *
 * Return: void
 */
void match_opcode(stack_t **stack, char *opcode_line, unsigned int line_nr)
{
	int i = 0;
	instruction_t match_func[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}};

	getvalue(opcode_line, line_nr);

	while (match_func[i].opcode != NULL)
	{
		if (strncmp(container.opcode_command,
			    match_func[i].opcode,
			    strlen(match_func[i].opcode)) == 0)
		{
			match_func[i].f(stack, line_nr);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_nr, opcode_line);
	exit(EXIT_FAILURE);
}
