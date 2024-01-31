#include "monty.h"

/**
 * pstr - Prints the string starting at
 * the top of the stack, followed by a new line
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	while (current != NULL && current->n != 0 &&
			current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
