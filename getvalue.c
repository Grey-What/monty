#include "monty.h"
/**
 * free_list - frees an array of pointers
 *
 * @list: array of pointers to free
 *
 * Return: void
 */
void free_list(char **list)
{
	int i = 0;

	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

/**
 * getvalue - extracts argument value from opcode line
 * @opcode_line: opcode line from file.
 * @line_nr: line number of opcode line in file
 * Return: void
 */
void getvalue(char *opcode_line, unsigned int line_nr)
{
	int i = 0, count = 0;
	char **list = NULL, *token = NULL, *temp;

	temp = strdup(opcode_line);
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(temp, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	free(temp);

	list = malloc(sizeof(char *) * (count + 1));
	if (list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(opcode_line, " ");
	while (token != NULL)
	{
		list[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (list[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(list[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	list[i] = NULL;
	container.opcode_command = strdup(list[0]);
	if (list[1] != NULL)
		container.value = atoi(list[1]);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_nr);
		exit(EXIT_FAILURE);
	}
	free_list(list);
}
