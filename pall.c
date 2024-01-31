#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
		return;

	/* Unused parameter (void) to suppress the warning */
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
