#include "monty.h"

/**
 * set_queue_format - sets the format of the data to a queue (FIFO)
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void set_queue_format(stack_t **linked_list_head, unsigned int line_number)
{
	(void)linked_list_head;
	(void)line_number;

	global_info.is_lifo = 0;
}

/**
 * set_stack_format - sets the format of the data to a stack (LIFO)
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void set_stack_format(stack_t **linked_list_head, unsigned int line_number)
{
	(void)linked_list_head;
	(void)line_number;

	global_info.is_lifo = 1;
}

/**
 * add_top_elements - adds the top two elements of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void add_top_elements(stack_t **linked_list_head, unsigned int line_number)
{
	int count = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, count++)
		;

	if (count < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	aux = (*linked_list_head)->next;
	aux->n += (*linked_list_head)->n;
	pop_top_element(linked_list_head, line_number);
}

/**
 * do_nothing - doesn't do anything
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void do_nothing(stack_t **linked_list_head, unsigned int line_number)
{
	(void)linked_list_head;
	(void)line_number;
}

/**
 * subtract_top_elements - subtracts the top element from the second top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void subtract_top_elements(stack_t **linked_list_head, unsigned int line_number)
{
	int count = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, count++)
		;

	if (count < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	aux = (*linked_list_head)->next;
	aux->n -= (*linked_list_head)->n;
	pop_top_element(linked_list_head, line_number);
}
