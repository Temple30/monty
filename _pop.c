#include "monty.h"

/**
 * customPop - removes the top element of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customPop(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;

    if (*stackHead == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;
    *stackHead = current->next;
    free(current);
}
