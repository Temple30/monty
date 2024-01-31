#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* Check if the stack is empty or has only one element */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	/* Traverse to the end of the stack */
	while (current->next != NULL)
		current = current->next;

	/* Move the last element to the top */
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
