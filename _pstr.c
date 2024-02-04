#include "monty.h"

/**
 * customPrintString - prints the string starting at the top of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customPrintString(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    (void)lineNumber;

    current = *stackHead;

    while (current)
    {
        if (current->n > 127 || current->n <= 0)
        {
            break;
        }
        printf("%c", current->n);
        current = current->next;
    }
    printf("\n");
}
