#include "monty.h"

/**
 * customModulo - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customModulo(stack_t **stackHead, unsigned int lineNumber)
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
        fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    result = current->next->n % current->n;
    current->next->n = result;
    *stackHead = current->next;
    free(current);
}
