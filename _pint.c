#include "monty.h"

/**
 * customPrintTopValue - prints the top element of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customPrintTopValue(stack_t **stackHead, unsigned int lineNumber)
{
    if (*stackHead == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stackHead)->n);
}
