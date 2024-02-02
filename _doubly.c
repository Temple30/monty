#include "monty.h"

/**
 * add_node_at_end - adds a node at the end of the doubly linked list
 * @list_head: pointer to the first position of the linked list
 * @data: data to store in the new node
 * Return: pointer to the doubly linked list
 */
stack_t *add_node_at_end(stack_t **list_head, const int data)
{
	stack_t *new_elem, *current_elem;

	if (list_head == NULL)
		return (NULL);

	new_elem = malloc(sizeof(stack_t));
	if (!new_elem)
	{
		dprintf(2, "Error: malloc failed\n");
		_new_free_vglo();
		exit(EXIT_FAILURE);
	}

	new_elem->n = data;

	if (*list_head == NULL)
	{
		new_elem->next = *list_head;
		new_elem->prev = NULL;
		*list_head = new_elem;
		return *(list_head);
	}

	current_elem = *list_head;
	while (current_elem->next)
		current_elem = current_elem->next;

	new_elem->next = current_elem->next;
	new_elem->prev = current_elem;
	current_elem->next = new_elem;

	return (current_elem->next);
}

/**
 * add_node_at_beginning - adds a node at the beginning of the doubly linked list
 * @list_head: pointer to the first position of the linked list
 * @data: data to store in the new node
 * Return: pointer to the doubly linked list
 */
stack_t *add_node_at_beginning(stack_t **list_head, const int data)
{
	stack_t *new_elem;

	if (list_head == NULL)
		return (NULL);

	new_elem = malloc(sizeof(stack_t));
	if (!new_elem)
	{
		dprintf(2, "Error: malloc failed\n");
		_new_free_vglo();
		exit(EXIT_FAILURE);
	}

	new_elem->n = data;

	if (*list_head == NULL)
	{
		new_elem->next = *list_head;
		new_elem->prev = NULL;
		*list_head = new_elem;
		return (*list_head);
	}

	(*list_head)->prev = new_elem;
	new_elem->next = (*list_head);
	new_elem->prev = NULL;
	*list_head = new_elem;

	return (*list_head);
}

/**
 * free_dlistint_nodes - frees the doubly linked list nodes
 * @list_head: head of the list
 * Return: no return
 */
void free_dlistint_nodes(stack_t *list_head)
{
	stack_t *current_elem;

	while ((current_elem = list_head) != NULL)
	{
		list_head = list_head->next;
		free(current_elem);
	}
}
