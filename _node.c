#include "monty.h"

/**
 * addToStack - adds a node to the head of the stack.
 * @stackHead: head of the stack
 * @value: new_value
 * Return: no return
 */
void addToStack(stack_t **stackHead, int value)
{
    stack_t *newNode, *current;

    current = *stackHead;
    newNode = malloc(sizeof(stack_t));

    if (newNode == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }

    if (current)
        current->prev = newNode;

    newNode->n = value;
    newNode->next = *stackHead;
    newNode->prev = NULL;

    *stackHead = newNode;
}
