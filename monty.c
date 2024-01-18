#define _GNU_SOURCE
#include "monty.h"
/**
 * main - entry point to monty interpreter/program
 *
 * @argc: argument count
 * @argv: list containing program name and arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	unsigned int line_nr = 0;
	char *opcode_line = NULL;
	size_t char_read = 0;
	FILE *opcode_file = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	opcode_file = fopen(argv[1], "r");
	if (opcode_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&opcode_line, &char_read, opcode_file) != -1)
	{
		line_nr++;
		match_opcode(&stack, opcode_line, line_nr);
		free(container.opcode_command);
		free(opcode_line);
		opcode_line = NULL;
	}
	free(opcode_line);
	fclose(opcode_file);
	free_stack(&stack);
	return (0);
}
