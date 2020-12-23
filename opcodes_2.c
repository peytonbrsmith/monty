#include "monty.h"
/**
* add - adds top two elements of the stack
* @stack: stack
* @line_number: number of line from read file
*
* Return: nothing, but exit != 0 on failure
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		head->next->n += head->n;
		pop(stack, line_number);
	}
}
/**
* mul - multiplies two nodes
* @stack: stack
* @line_number: line number from read file
*
* Return: nothing, but exits with value FAILURE on fail
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		head->n *= head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}
/**
* nop - you ever hear about the funny man
* @stack: the funny man sat here, counting his grapes
* @line_number: dont tell anyone, but this is how many toes funny man has
* Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	/* purposefully does nothing */
	stack = stack;
	line_number = line_number;
}
