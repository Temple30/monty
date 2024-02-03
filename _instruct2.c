#include "monty.h"

/**
 * divide_top_elements - divides the second element by the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void divide_top_elements(stack_t **linked_list_head, unsigned int line_number)
{
	int element_count = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *linked_list_head;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, element_count++)
		;

	if (element_count < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*linked_list_head)->next;
	auxiliary->n /= (*linked_list_head)->n;
	divide_top_elements(linked_list_head, line_number);
}

/**
 * multiply_top_elements - multiplies the top element to the second top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void multiply_top_elements(stack_t **linked_list_head, unsigned int line_number)
{
	int element_count = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *linked_list_head;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, element_count++)
		;

	if (element_count < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*linked_list_head)->next;
	auxiliary->n *= (*linked_list_head)->n;
	divide_top_elements(linked_list_head, line_number);
}

/**
 * compute_modulus - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void compute_modulus(stack_t **linked_list_head, unsigned int line_number)
{
	int element_count = 0;
	stack_t *auxiliary = NULL;

	auxiliary = *linked_list_head;

	for (; auxiliary != NULL; auxiliary = auxiliary->next, element_count++)
		;

	if (element_count < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	auxiliary = (*linked_list_head)->next;
	auxiliary->n %= (*linked_list_head)->n;
	divide_top_elements(linked_list_head, line_number);
}

/**
 * print_char_value - print the char value of the first element
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void print_char_value(stack_t **linked_list_head, unsigned int line_number)
{
	if (linked_list_head == NULL || *linked_list_head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	if ((*linked_list_head)->n < 0 || (*linked_list_head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*linked_list_head)->n);
}

/**
 * print_stack_string - prints the string of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void print_stack_string(stack_t **linked_list_head, unsigned int line_number)
{
	stack_t *auxiliary;
	(void)line_number;

	auxiliary = *linked_list_head;

	while (auxiliary && auxiliary->n > 0 && auxiliary->n < 128)
	{
		printf("%c", auxiliary->n);
		auxiliary = auxiliary->next;
	}

	printf("\n");
}
