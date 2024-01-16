#include "monthy.h"
/**
 * match_opcode - matching file line text to relevant function
 *
 * @opcode_line: line of opcode
 *
 * Return: void
 */
void match_opcode(char *opcode_line)
{
	int i = 0;
	stack_t *pointer = malloc(sizeof(stack_t));
	if (pointer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction_t match_func[] = {
		{"push", push}, {"pall", pall}; {NULL, NULL}};

	while (match_func[i].opcode != NULL)
	{
		if (strncmp(opcode_line, match_func.opcode, len(match_func.opcode[]) == 0)
			{
				match_func[i].f(&pointer, line_nr);
			}
	}
	fprintf(sterr, "L%d: unknown instruction %s\n", line_nr, opcode_line);
	exit(EXIT_FAILURE);
}
