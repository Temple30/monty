#include "monty.h"

/**
 * customSwap - swaps the top two elements of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customSwap(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int stackLength = 0, temp;

    current = *stackHead;
    while (current)
    {
        current = current->next;
        stackLength++;
    }

    if (stackLength < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;
    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}
