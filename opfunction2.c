#include "monty.h"
/**
 * mop - prints the top
 * @head: ptr to the stack
 * @count: line number
 * Return: nothing
 */
void mop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		freeExit(head, EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;

	free(temp);
}

#include "monty.h"
/**
 * montywap - adds the top two elements of the stack.
 * @head: pointer to stack
 * @count: line number
 * Return: nothing
*/
void montywap(stack_t **head, unsigned int count)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL) 
	{
        fprintf(stderr, "L%d: can't swap, stack too short\n", count);
        freeExit(head, EXIT_FAILURE);
        return;
    }

    temp = (*head)->n;
   (*head)->n = (*head)->next->n;
   (*head)->next->n = temp;
}

#include "monty.h"
/**
 * madd - adds the top two elements of the stack.
 * @head: pointer to stack
 * @count: line number
 * Return: nothing
*/
void madd(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int nodeNum = 0;
	int hold;

	temp = *head;

	while (temp != NULL)
	{
		temp = temp->next;
		nodeNum++;
	}

	if (nodeNum < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		freeExit(head, EXIT_FAILURE);
	}

	temp = *head;
	hold = temp->n + temp->next->n;
	temp->next->n = hold;
	*head = temp->next;

	free(temp);
}

#include "monty.h"
/**
  *nope - nothing
  *@head: pointer to stack
  *@counter: line_number
  *Return: no return
 */
void nope(stack_t **head, unsigned int count)
{
	(void) head;
(void) count;
}

