#include "monty.h"

/**
 * customPush - adds a node to the stack.
 * @stackHead: stack head
 * @lineNumber: line_number
 * Return: no return
 */
void customPush(stack_t **stackHead, unsigned int lineNumber)
{
    int value, index = 0, flag = 0;

    if (bus.argument_value)
    {
        if (bus.argument_value[0] == '-')
            index++;
        for (; bus.argument_value[index] != '\0'; index++)
        {
            if (bus.argument_value[index] > '9' || bus.argument_value[index] < '0')
                flag = 1;
        }
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
            fclose(bus.file);
            free(bus.content);
            free_stack(*stackHead);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stackHead);
        exit(EXIT_FAILURE);
    }

    value = atoi(bus.argument_value);

    if (bus.lifi == 0)
        addToStack(stackHead, value);
    else
        addToQueue(stackHead, value);
}
