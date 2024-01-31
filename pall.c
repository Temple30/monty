#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
		return;

	/* Print all values on the stack */
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
