#include "monty.h"
int nodeval;
/**
* push - adds a node to the stack
* @stack: stack
* @line_number: number of line read from file
*
* Return: nothing, but exits with value != 0 on fail
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	line_number = line_number;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		errno = -1;
		return;
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
}
/**
* pall - prints the stack
* @stack: stack
* @line_number: line number from read file
* Return: nothing, but exits != 0 if fail
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;

	if (stack == NULL) /* prints nothing if stack is empty */
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
/**
* pint - prints the node at top of stack
* @stack: stack
* @line_number: number of line from read file
* Return: nothing, exit != 0 on fail
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		current = *stack;
		printf("%d\n", current->n);
	}
}
/**
* pop - deletes a node from the stack
* @stack: stack
* @line_number: line number from read file
*
* Return: nothing, exit != 0 on fail
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		errno = -1;
		return;
	}
	else
	{
		next = head->next;
		free(head);
		next->prev = NULL;
		*stack = next;
	}
}
/**
* swap - swaps top elements of the stack
* @stack: stack
* @line_number: line number from read file
*
* Return: nothing, exit != 0 on fail
*/
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
		errno = -1;
		return;
	}
}
