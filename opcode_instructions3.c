#include "monty.h"

/**
 * montyDiv - divides the second element by the top element of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyDiv(stack_t **dhead, unsigned int lNum)
{
	int count;
	stack_t *temp = NULL;

	temp = *dhead;

	for (count = 0; temp != NULL; temp = temp->next, count++)
		;

	if (count < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	if ((*dhead)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	temp = (*dhead)->next;
	temp->n /= (*dhead)->n;
	montyPop(dhead, lNum);
}

/**
 * montyMul - multiplies the top element to the second top element of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyMul(stack_t **dhead, unsigned int lNum)
{
	int count;
	stack_t *hold = NULL;

	hold = *dhead;

	for (count = 0; hold != NULL; hold = hold->next, count++);

	if (count < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	hold = (*dhead)->next;
	hold->n *= (*dhead)->n;
	montyPop(dhead, lNum);
}

/**
 * montyMod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyMod(stack_t **dhead, unsigned int lNum)
{
	int elCount;
	stack_t *temp = NULL;

	temp = *dhead;

	for (elCount = 0; temp != NULL; temp = temp->next, elCount++)
		;

	if (elCount < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	if ((*dhead)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}

	temp = (*dhead)->next;
	temp->n %= (*dhead)->n;
	montyPop(dhead, lNum);
}
/**
 * montyPchar - print the char value of the first element
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyPchar(stack_t **dhead, unsigned int lNum)
{
	if (dhead == NULL || *dhead == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", lNum);
		frevarG();
		exit(EXIT_FAILURE);
	}
	if ((*dhead)->n < 0 || (*dhead)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", lNum);
		freevarG();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dhead)->n);
}

/**
 * montyPstr - prints the string of the stack
 *
 * @dhead: head of the linked list
 * @lNum: line number;
 * Return: no return
 */
void montyPstr(stack_t **dhead, unsigned int lNum)
{
	stack_t *currElement;
	(void)lNum;

	currElement = *dhead;

	while (currElement != 0 && currElement->n > 0 && currElement->n < 128)
	{
		printf("%c", currElement->n);
		currElement = currElement->next;
	}

	printf("\n");
}
