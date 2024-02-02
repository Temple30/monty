#include "monty.h"

/**
 * push_element - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push_element(stack_t **linked_list_head, unsigned int line_number)
{
	int input_value, index;

	if (!global_info.argument_value)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		release_global_info();
		exit(EXIT_FAILURE);
	}

	for (index = 0; global_info.argument_value[index] != '\0'; index++)
	{
		if (!isdigit(global_info.argument_value[index]) && global_info.argument_value[index] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			release_global_info();
			exit(EXIT_FAILURE);
		}
	}

	input_value = atoi(global_info.argument_value);

	if (global_info.is_lifo == 1)
		add_node_at_beginning(linked_list_head, input_value);
	else
		add_node_at_end(linked_list_head, input_value);
}

/**
 * print_all_values - prints all values on the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void print_all_values(stack_t **linked_list_head, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *linked_list_head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * print_top_value - prints the value at the top of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void print_top_value(stack_t **linked_list_head, unsigned int line_number)
{
	(void)line_number;

	if (*linked_list_head == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		release_global_info();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*linked_list_head)->n);
}

/**
 * pop_top_element - removes the top element of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pop_top_element(stack_t **linked_list_head, unsigned int line_number)
{
	stack_t *aux;

	if (linked_list_head == NULL || *linked_list_head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}
	aux = *linked_list_head;
	*linked_list_head = (*linked_list_head)->next;
	free(aux);
}

/**
 * swap_top_elements - swaps the top two elements of the stack
 *
 * @linked_list_head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void swap_top_elements(stack_t **linked_list_head, unsigned int line_number)
{
	int count = 0;
	stack_t *aux = NULL;

	aux = *linked_list_head;

	for (; aux != NULL; aux = aux->next, count++)
		;

	if (count < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		release_global_info();
		exit(EXIT_FAILURE);
	}

	aux = *linked_list_head;
	*linked_list_head = (*linked_list_head)->next;
	aux->next = (*linked_list_head)->next;
	aux->prev = *linked_list_head;
	(*linked_list_head)->next = aux;
	(*linked_list_head)->prev = NULL;
}
