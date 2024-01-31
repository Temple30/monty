#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack contains less than two elements */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Subtract the top element from the second top element */
	(*stack)->next->n -= (*stack)->n;

	/* Remove the top element */
	pop(stack, line_number);
}
