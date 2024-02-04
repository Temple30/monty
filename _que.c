#include "monty.h"

/**
 * customQueueMode - sets the stack mode to queue.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customQueueMode(stack_t **stackHead, unsigned int lineNumber)
{
    (void)stackHead;
    (void)lineNumber;
    bus.lifi = 1;
}

/**
 * addToQueue - adds a node to the tail of the stack.
 * @value: new_value
 * @stackHead: head of the stack
 * Return: no return
 */
void addToQueue(stack_t **stackHead, int value)
{
    stack_t *newNode, *current;

    current = *stackHead;
    newNode = malloc(sizeof(stack_t));

    if (newNode == NULL)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = value;
    newNode->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *stackHead = newNode;
        newNode->prev = NULL;
    }
    else
    {
        current->next = newNode;
        newNode->prev = current;
    }
}
