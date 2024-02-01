#include "monty.h"

/**
 * montyRotl - rotates the first element to the bottom and  the second to the top
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: nothing
 */
void montyRotl(stack_t **dhead, unsigned int lNum)
{
	stack_t *tempA = NULL;
	stack_t *tempB = NULL;
	(void)lNum;

	if (*dhead == NULL)
		return;

	if ((*dhead)->next == NULL)
		return;

	tempA = (*dhead)->next;
	tempB = *dhead;

	for (; tempB->next != NULL; tempB = tempB->next)
;
	tempA->prev = NULL;
	tempB->next = *dhead;
	(*dhead)->next = NULL;
	(*dhead)->prev = tempB;
	*dhead = tempA;
}

/**
 * montyRotr - reverses the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number
 * Return: nothing
 */
void montyRotr(stack_t **dhead, unsigned int lNum)
{
	stack_t *temp = NULL;
	(void)lNum;

	if (*dhead == NULL)
		return;

	if ((*dhead)->next == NULL)
		return;

	temp = *dhead;

	for (; temp->next != NULL; temp = temp->next);

	temp->prev->next = NULL;
	temp->next = *dhead;
	temp->prev = NULL;

	(*dhead)->prev = temp;
	*dhead = temp;
}

