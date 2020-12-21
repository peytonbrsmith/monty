#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	line_number = line_number;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{

	}
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
	stack_t *head = *stack;
	stack_t *temp;

	if (head != NULL && head->next != NULL)
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		head->next->prev = temp;
		temp->next = head->next;
		head->next = temp;
		*stack = head;
	}
	else
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	}
}

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	else
	{
		head->n += head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	else
	{
		head->n *= head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}

void nop(stack_t **stack, unsigned int line_number)
{
	/* purposefully does nothing */
	stack = stack;
	line_number = line_number;
}
