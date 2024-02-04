#include "monty.h"

/**
 * customMultiply - multiplies the top two elements of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customMultiply(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int length = 0, result;

    current = *stackHead;

    while (current)
    {
        current = current->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;
    result = current->next->n * current->n;
    current->next->n = result;
    *stackHead = current->next;
    free(current);
}
