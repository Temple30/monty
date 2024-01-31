#include "monty.h"

/**
 * print_to_stdout - Prints a message to the standard output.
 * @message: The message to be printed.
 *
 * Description: This function prints the
 * specified message to the standard output.
 * It is used for providing information
 * about the success of operations.
 */
void print_to_stdout(const char *message)
{
	printf("%s", message);
}

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the file.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 */
void push(stack_t **stack, unsigned int line_number, int argc, char *argv[])
{
	(void)stack;

	int value;
	value = atoi(avrg[1]);
	stack_t *new_node = malloc(sizeof(stack_t));

	/* Check if there is an argument provided */
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
