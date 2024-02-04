#include "monty.h"
/**
 * mush - push node to top of stack
 * @head: ptr to the stack
 * @count: line number
 * Return: nothing
*/
void mush(stack_t **head, unsigned int count)
{
	{
       int num, i = 0;
       bool isNum = true;

       if (varG.data)
       {

               if (varG.data[i] == '-')
                       i++;
               for(; varG.data[i] != '\0'; i++)
               {
                       if (varG.data[i] > '9' || varG.data[i] < '0')
                               isNum = false;
                                       }
               if (isNum == false)
               { fprintf(stderr, "L%d: usage: push integer\n", count);
                       freeExit(head, EXIT_FAILURE); }
                       }
       else
       { fprintf(stderr, "L%d: usage: push integer\n", count);
               freeExit(head, EXIT_FAILURE);
       }
       num = atoi(varG.data);

       if (varG.stackQ == 0)
               nodeNew(head, num);
       else
               queueNew(head, num);
}
}

#include "monty.h"
/**
 * mall - prints the stack
 * @head: ptr to the stack
 * @count: unused arg
 * Return: nothing
*/
void mall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

#include "monty.h"
/**
 * mint - prints the top
 * @head: ptr to the stack
 * @count: line number
 * Return: nothing
*/
void mint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		freeExit(head, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
