#include "monty.h"

extern int nodeval;

int main(int argc, char **argv)
{
	stack_t **stack = NULL;
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
		fd = fopen(argv[1], "r"); /* opens file */
		line_size = getline(&line, &bufsize, fd); /* reads first line */
		while (line_size >= 0) /* continues reading lines if they exist */
		{
			line_number++;
			if (line_size > 1) /* if line isn't blank */
				parse(line, stack, line_number);
			line_size = getline(&line, &bufsize, fd);
		}
		free(line);
		line = NULL;
		fclose(fd); /* close the file */
	}
	return (EXIT_SUCCESS);
}

void parse(char *line, stack_t **stack, unsigned int line_number)
{
	char *linedup = NULL, *opcode = NULL, *value = NULL;
	char *del = " \t\r\n\f\v";

	linedup = strdup(line); /* dup line */

	opcode = strtok(linedup, del); /* grab opcode */
	value = strtok(NULL, del); /* grab value if there is one */
	if (value)
	{
		nodeval = atoi(value);
	}
	chkopcode(opcode, stack, line_number); /* checks if opcode exists */
	free(linedup);
}

void chkopcode(char* opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	char *ui = "unknown instruction";

	instruction_t opcodes[] = { /* opcodes supported */
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0) /* matches opcode str with func */
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: %s %s\n", line_number, ui, opcode); /* error if no opcode */
}
