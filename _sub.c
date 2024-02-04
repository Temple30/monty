#include "monty.h"

/**
 * customSubtraction - performs subtraction on the top two elements of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customSubtraction(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int result, nodeCount;

    current = *stackHead;
    for (nodeCount = 0; current != NULL; nodeCount++)
        current = current->next;

    if (nodeCount < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;
    result = current->next->n - current->n;
    current->next->n = result;
    *stackHead = current->next;
    free(current);
}
