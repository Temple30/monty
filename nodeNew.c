#include "monty.h"
/**
 * nodeNew - add node to top of stack
 * @head: pointer to stack
 * @n: value
 * Return: nothing
 */
void nodeNew(stack_t **head, int n)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL) {
        printf("Error\n");
        exit(0);
    }

    new->n = n;
    new->next = *head;
    new->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new;
    }

    *head = new;
}

/**
 * queueNew - add node to the end of a stack
 * @n: value
 * @head: pointer to stack
 * Return: nothing
*/
void queueNew(stack_t **head, int n)
{
    stack_t *tail;
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return;
    }

    new->n = n;
    new->next = NULL;

   if (*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }

    tail = (*head)->prev;
    tail->next = new;
    new->prev = tail;
    (*head)->prev = new;
}
