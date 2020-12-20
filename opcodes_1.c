#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "PUSH", nodeval);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "PALL", nodeval);
}

void pint(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	printf("L%d: OPCODE: %s NODEVAL: %d\n", line_number, "PINT", nodeval);
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
