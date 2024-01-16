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
	int line_nr = 0;
	FILE *opcode = NULL;
	char *opcode_line = NULL;
	size_t char_read = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	opcode = fopen(argv[1], "r");
	if (opcode == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&opcode_line, &char_read, opcode) != -1)
	{
		match_opcode(opcode_line);
	}
	return (0);
}
