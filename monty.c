#include "monty.h"
int nodeval;
/**
* main - grabs arguments and sends them to be parsed
* @argc: count of arguments
* @argv: arguments
*
* Return: any value !~ 0 fail, otherwise exits with success
*/
int main(int argc, char **argv)
{
	stack_t *stack;
	FILE *fd;
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t line_size = 0;
	unsigned int line_number = 0;

	if (argc > 2 || argc < 2) /* checks for correct usage of monty */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0) /* checks for file read permission */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack = NULL;
		fd = fopen(argv[1], "r"); /* opens file */
		line_size = getline(&line, &bufsize, fd); /*rd first line*/
		while (line_size >= 0 && errno == 0) /* continues reading */
		{
			line_number++;
			if (line_size > 1) /* if line isn't blank */
			errno = parse(line, &stack, line_number);
			line_size = getline(&line, &bufsize, fd);
		}
		if (stack != NULL)
			free_Stack(&stack); /* if stack isn't empty free it */
		free(line);
		fclose(fd); /* close the file */
		if (errno != 0)
			exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/**
* parse - parses each argument into tokens and passes them to checker
* @line: line buffer from user read
* @stack: stack
* @line_number: line number from read file
*
* Return: -1 on fail, otherwise on success
*/
int parse(char *line, stack_t **stack, unsigned int line_number)
{
	char *linedup = NULL, *opcode = NULL, *value = NULL, *del = " \t\r\n";

	linedup = strdup(line); /* dup line */
	opcode = strtok(linedup, del); /* grab opcode */
	value = strtok(NULL, del); /* grab value if there is one */
	if (value != NULL)
	{
		if (strcmp(opcode, "push") < 0)
		{ /* Checks if argument is given to non-push opcode*/
			fprintf(stderr, "L%d: usage %s\n", line_number, opcode);
			free(linedup);
			return (-1);
		}
		else
			nodeval = atoi(value); /* sets nodeval to int */
	}
	else if (value == NULL && (strcmp(opcode, "push") == 0))
	{ /* Checks if push doesn't get an argument*/
		fprintf(stderr, "L%d: usage push integer\n", line_number);
		free(linedup);
		return (-1);
	}
	if (chkopcode(opcode, stack, line_number) == 0)
	{ /* checks if opcode exists */
		free(linedup);
		return (0);
	}
	free(linedup);
	return (-1);
}
/**
* chkopcode - checks opcodes
* @opcode: opcode to verify
* @stack: stack
* @line_number: line from read file
*
* Return: -1 on fail, 0 on success
*/
int chkopcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	 /* opcodes supported */
	instruction_t opcodes[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"mul", mul},
		{NULL, NULL}
	};
	/*loop through opcode*/
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)/*finds func*/
		{
			opcodes[i].f(stack, line_number); /*opcode check*/
			return (errno);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	return (errno);
}
/**
* free_Stack - frees a doubly linked list, in this case a stack
* @stack: stack
*
* Return: nothing
*/
void free_Stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
