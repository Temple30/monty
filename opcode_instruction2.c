#include "monty.h"

/**
 * montyQueue - sets the format of the data to a queue (FIFO)
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyQueue(stack_t **dhead, unsigned int lNum)
{
	(void)dhead;
	(void)lNum;

	varG.islifo = 0;
}

/**
 * montyStack - sets the format fo the data to a stack (LIFO)
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyStack(stack_t **dhead, unsigned int lNum)
{
	(void)dhead;
	(void)lNum;

	varG.islifo = 1;
}

/**
 * montyAdd - adds the top two elements of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyAdd(stack_t **dhead, unsigned int lNum)
{
	int elNum;
	stack_t *secElem = NULL;

	secElem = *dhead;

	for (elNum = 0; secElem != NULL; secElem = secElem->next, m++)
		;

	if (elNum < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	secElem = (*dhead)->next;
	secElem->n += (*dhead)->n;
	montyPop(dhead, lNum);
}

/**
 * montyNop - doesn't do anythinhg
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyNop(stack_t **dhead, unsigned int lNum)
{
	(void)dhead;
	(void)lNum;
}

/**
 * montySub - subtracts the top element to the second top element of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montySub(stack_t **dhead, unsigned int lNum)
{
	int elNum;
	stack_t *secElem = NULL;

	secElem = *dhead;

	for (elNum = 0; secElem != NULL; secElem = secElem->next, m++);

	if (elNum < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	secElem = (*dhead)->next;
	secElem->n -= (*dhead)->n;
	montyPop(dhead, lNum);
}
