#include "monty.h"

/**
 * div_op - Divides the second top element of the stack by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack contains less than two elements */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Check if the top element of the stack is 0 */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Divide the second top element by the top element */
	(*stack)->next->n /= (*stack)->n;

	/* Remove the top element */
	pop(stack, line_number);
}
