#include "monty.h"

/**
 * customFreeStack - frees a doubly linked list.
 * @stackHead: head of the stack
 */
void customFreeStack(stack_t *stackHead)
{
    stack_t *current;

    current = stackHead;
    while (stackHead)
    {
        current = stackHead->next;
        free(stackHead);
        stackHead = current;
    }
}
