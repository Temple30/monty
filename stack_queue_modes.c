#include "monty.h"

/**
 * stack_mode - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	/* This opcode is used to set the format of the data to a stack (LIFO) */
}

/**
 * queue_mode - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* This opcode is used to set the format of the data to a queue (FIFO) */

	/* If the stack is empty or has only one element, no need to switch */
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	/* Traverse to the end of the stack */
	while (current->next != NULL)
		current = current->next;

	/* Switch the top of the stack and the front of the queue */
	current->prev->next = NULL;
	current->prev = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
}
