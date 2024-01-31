#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is in the ASCII range */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c\n", (*stack)->n);
}
