#include "monty.h"

/**
 * customRotateRight - rotates the stack to the bottom.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customRotateRight(stack_t **stackHead, __attribute__((unused)) unsigned int lineNumber)
{
    stack_t *copy;

    copy = *stackHead;

    if (*stackHead == NULL || (*stackHead)->next == NULL)
    {
        return;
    }

    while (copy->next)
    {
        copy = copy->next;
    }

    copy->next = *stackHead;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*stackHead)->prev = copy;
    (*stackHead) = copy;
}
