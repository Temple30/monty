#include "monty.h"
/**
 * freeExit - cleans up, exits after error
 * @head: pointer to stack*/

void freeExit(stack_t **head, int exit_code)
{
    fclose(varG.file);
    free(varG.theOps);
    freeDLL(*head);
    exit(exit_code);
}

/**
* freeDLL - frees a dll
* @head: pointer to the stack
*/
void freeDLL(stack_t *head)
{
	stack_t *temp;
	temp = head;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
