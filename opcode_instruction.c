#include "monty.h"

/**
 * montyPush - pushes an element to the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number
 * Return: no return
 */
void montyPush(stack_t **dhead, unsigned int lNumber)
{
	int val;
	int i;

	if (varG.arg == NULL)
	{
		dprintf(2, "L%u: ", lNumber);
		dprintf(2, "usage: push integer\n");
		freevarG();
		exit(EXIT_FAILURE);
	}

	for (i = 0; varG.arg[i] != '\0'; i++)
	{
		if (!isdigit(varG.arg[i]) && varG.arg[i] != '-')
		{
			dprintf(2, "L%u: ", lNumber);
			dprintf(2, "usage: push integer\n");
			freevarG();
			exit(EXIT_FAILURE);
		}
	}

	val = atoi(varG.arg);

	if (varG.islifo == 1)
	
		addBeg(dhead, val);
	else
		addEnd(dhead, val);
}

/**
 * montyPall - prints all values on the stack, from top
 *
 * @dhead: head of the linked list
 * @lNum: line numbers
 * Return: no return
 */
void montyPall(stack_t **dhead, unsigned int lNum)
{
	stack_t *temp;
	(void)lNum;

	temp = *dhead;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * montyPint - prints the value at the top of the stack
 * followed by new line
 * @dhead: head of the linked list
 * @lNum: line number
 * Return: no return
 */
void montyPint(stack_t **dhead, unsigned int lNum)
{
	(void)lNum;

	if (*dhead == NULL)
	{
		dprintf(2, "L%u: ", lNum);
		dprintf(2, "can't pint, stack empty\n");
		freevarG();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dhead)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number
 * Return: no return
 */
void _pop(stack_t **dhead, unsigned int lNum)
{
	stack_t *temp;

	if (dhead == NULL || *dhead == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}
	temp = *dhead;
	*dhead = (*dhead)->next;

	free(temp);
}

/**
 * montySwap - swaps the top two elements of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number
 * Return: no return
 */
void montySwap(stack_t **dhead, unsigned int lNum)
{
	int counter;

	stack_t *hold = NULL;
	counter = 0;

	hold = *dhead;

	for (counter = 0; hold != NULL; hold = hold->next, counter++);

	if (counter < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	hold = *dhead;
	*dhead = (*dhead)->next;
	hold->next = (*dhead)->next;
	hold->prev = *dhead;
	(*dhead)->next = hold;
	(*dhead)->prev = NULL;
}

