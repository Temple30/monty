#include "monty.h"

/**
 * customAdd - adds the top two elements of the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customAdd(stack_t **stackHead, unsigned int lineNumber)
{
    stack_t *current;
    int stackLength = 0, result;

    current = *stackHead;
    while (current)
    {
        current = current->next;
        stackLength++;
    }

    if (stackLength < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    current = *stackHead;
    result = current->n + current->next->n;
    current->next->n = result;
    *stackHead = current->next;
    free(current);
}
    /**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *aux;

    aux = head;
    while (head)
    {
        aux = head->next;
        free(head);
        head = aux;
    }
}
