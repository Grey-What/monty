#include "monty.h"
/**
 * check_number - checks if a string can be a number
 *
 * @str: string to check
 *
 * Return: 1 if it is a number  or 0 if not
 */
int check_number(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
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
 * token_count - counts number of tokens
 *
 * @opcode_line: string to tokenize
 *
 * Return: number of tokens
 */
int token_count(char *opcode_line)
{
	char *temp, *token = NULL;
	int count = 0;

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
	return (count);
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
	(void)line_nr;

	count = token_count(opcode_line);

	list = malloc(sizeof(char *) * (count + 1));
	if (list == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp = strdup(opcode_line);
	token = strtok(temp, " ");
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
	free(temp);

	container.opcode_command = strdup(list[0]);
	if (count > 1 && (strcmp(list[0], "push") != 0))
	{
		fprintf(stderr, "L%d: unknown instruction %s",
			line_nr, opcode_line);
		exit(EXIT_FAILURE);
	}
	else if (list[1] != NULL && (strcmp(list[0], "push") == 0))
	{
		if (check_number(list[1]) != 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s",
			line_nr, opcode_line);
			exit(EXIT_FAILURE);
		}
		else
			container.value = atoi(list[1]);
	}
	free_list(list);
}
