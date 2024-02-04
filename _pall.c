#include "monty.h"

/**
 * customPrintAll - prints all elements of the stack.
 * @stackHead: stack head
 * @lineNumber: not used
 * Return: no return
 */
void customPrintAll(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    (void)lineNumber;

    current = *stackHead;

    if (current == NULL)
        return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
