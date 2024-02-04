#include "monty.h"

/**
 * customPrintChar - prints the char at the top of the stack, followed by a new line.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customPrintChar(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;

    current = *stackHead;

    if (!current)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    if (current->n > 127 || current->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", current->n);
}
