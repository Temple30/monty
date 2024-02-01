#include "monty.h"

/**
 *addEnd - add a node to the end of the dll
 *@dhead: head of dll
 *@n: data stored in dll
 *Return: ptr to dll
 */
stack_t *addEnd(stack_t **dhead, const int n)
{
	stack_t *temp, *aux;

	if (dhead == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		freevarG();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	
	if (*dhead == NULL)
	{
		temp->next = *dhead;
		temp->prev = NULL;
		*dhead = temp;
		return (*dhead);
	}
	aux = *dhead;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 *addBeg - adds a node to the beginning of a dll
 *@dhead: head of linked list
 *@n: data stored
 *Return: pointer to dll
 */
stack_t *addBeg(stack_t **dhead, const int n)
{
	stack_t *temp;

	if (dhead == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		freevarG();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	
	if (*dhead == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*dhead = temp;
		return (*dhead);
	}
	(*dhead)->prev = temp;
	temp->next = (*dhead);
	temp->prev = NULL;
	*dhead = temp;
	return (*dhead);
}

/**
 * freeDLL - frees a dll
 *
 * @dhead: head of the list
 * Return: no return
 */
void freeDLL(stack_t *dhead)
{
	stack_t *temp;

	while ((temp = dhead) != NULL)
	{
		dhead = dhead->next;
		free(temp);
	}
}
