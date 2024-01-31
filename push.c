#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 */
void push(stack_t **stack, unsigned int line_number, int argc, char *argv[])
{
	int value;
	stack_t *new_node;
	(void) stack;
       

	new_node = malloc(sizeof(stack_t));
	
	value = atoi(argv[1]);

	if (argc < 2)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
