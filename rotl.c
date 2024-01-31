#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
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
	current->next = *stack;
	(*stack)->prev = current;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	current->next->next = NULL;
}
