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
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
	}
	else
	{
	current = *stack;
	printf("%d\n", current->n);
	}
}

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
	}
	else
	{
		next = head->next;
		free(head);
		next->prev = NULL;
		*stack = next;
	}
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
