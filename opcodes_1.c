#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	line_number = line_number;

	temp = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		temp->n = nodeval;
		temp->next = NULL;
		temp->prev = NULL;
		*stack = temp;
		return;
	}
	temp->n = nodeval;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	return;
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;

	if (stack == NULL)
	{
		printf("\n");
		return;
	}
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;

	if (stack == NULL)
	{
		printf("L%d: can't pint, stack empty", line_number);
		return;
	}
	current = *stack;
	printf("%d\n", current->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "POP", nodeval);
}

void swap(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "SWAP", nodeval);
}

void add(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "ADD", nodeval);
}

void nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "NOP", nodeval);
}
