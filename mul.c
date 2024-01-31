#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack contains less than two elements */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Multiply the second top element by the top element */
	(*stack)->next->n *= (*stack)->n;

	/* Remove the top element */
	pop(stack, line_number);
}
