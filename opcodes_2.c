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
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		head->n += head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
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
	(void) stack;
	(void) line_number;
}
/**
* _div - divides the first two nodes of the stack
* @stack: stack of data
* @line_number: number_line from read file
*
* Return: nothing
*/
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		errno = -1;
		return;
	}
	else
	{
		head->n /= head->next->n;
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
}
/**
* sub - subtracts the first two nodes of the stack
* @stack: stack of data
* @line_number: line_number from read file
*
* Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
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
