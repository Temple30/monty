#include "monty.h"

/**
 * customRotateLeft - rotates the stack to the top.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customRotateLeft(stack_t **stackHead,  __attribute__((unused)) unsigned int lineNumber)
{
    stack_t *current = *stackHead, *temp;

    if (*stackHead == NULL || (*stackHead)->next == NULL)
    {
        return;
    }

    temp = (*stackHead)->next;
    temp->prev = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *stackHead;
    (*stackHead)->next = NULL;
    (*stackHead)->prev = current;
    (*stackHead) = temp;
}
