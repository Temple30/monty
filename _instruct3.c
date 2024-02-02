#include "monty.h"

/**
 * rotate_left - rotates the first element to the bottom and the second to the top
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void rotate_left(stack_t **linked_list_head, unsigned int line_number)
{
	stack_t *second_node = NULL;
	stack_t *last_node = NULL;
	(void)line_number;

	if (*linked_list_head == NULL)
		return;

	if ((*linked_list_head)->next == NULL)
		return;

	second_node = (*linked_list_head)->next;
	last_node = *linked_list_head;

	for (; last_node->next != NULL; last_node = last_node->next)
		;

	second_node->prev = NULL;
	last_node->next = *linked_list_head;
	(*linked_list_head)->next = NULL;
	(*linked_list_head)->prev = last_node;
	*linked_list_head = second_node;
}

/**
 * reverse_stack - reverses the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void reverse_stack(stack_t **linked_list_head, unsigned int line_number)
{
	stack_t *current_node = NULL;
	(void)line_number;

	if (*linked_list_head == NULL)
		return;

	if ((*linked_list_head)->next == NULL)
		return;

	current_node = *linked_list_head;

	for (; current_node->next != NULL; current_node = current_node->next)
		;

	current_node->prev->next = NULL;
	current_node->next = *linked_list_head;
	current_node->prev = NULL;
	(*linked_list_head)->prev = current_node;
	*linked_list_head = current_node;
}
