#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack contains less than two elements */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add the top two elements of the stack */
	(*stack)->next->n += (*stack)->n;

	/* Remove the top element */
	pop(stack, line_number);
}
