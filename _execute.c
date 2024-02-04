#include "monty.h"

/**
 * performOperation - executes the opcode.
 * @lineContent: line content
 * @stack: head linked list - stack
 * @lineNumber: line_counter
 * @montyFile: pointer to monty file
 * Return: no return
 */
int performOperation(char *lineContent, stack_t **stack, unsigned int lineNumber, FILE *montyFile)
{
    instruction_t operations[] = {
        {"push", customPush}, {"pall", customPrintAll}, {"pint", customPrintTopValue},
        {"pop", customPop},
        {"swap", customSwap},
        {"add", customAdd},
        {"nop", customNoOperation},
        {"sub", customSubtraction},
        {"div", customDivide},
        {"mul", customMultiply},
        {"mod", customModulo},
        {"pchar", customPrintChar},
        {"pstr", customPrintString},
        {"rotl", customRotateLeft},
        {"rotr", customRotateRight},
        {"queue", customQueueMode},
        {"stack", customQueueMode},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *opcode;

    opcode = strtok(lineContent, " \n\t");
    if (opcode && opcode[0] == '#')
        return 0;

    bus.argument_value = strtok(NULL, " \n\t");

    while (operations[i].opcode && opcode)
    {
        if (strcmp(opcode, operations[i].opcode) == 0)
        {
            operations[i].f(stack, lineNumber);
            return 0;
        }
        i++;
    }

    if (opcode && operations[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
        fclose(montyFile);
        free(lineContent);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}
