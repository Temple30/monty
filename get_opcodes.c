#include "monty.h"

/**
 * callMethod - selects the correct opcode based on keyword
 * 
 * @key: keyword passed to call function
 * Return: pointer to opcode function
 */

void (*callMethod(char *key))(stack_t **stack, unsigned int lNum)
{
	instruction_t opFunct[] = {
		{"push", montyPush},
		{"pall", montyPall},
		{"pint", montyPall},
		{"pop", montyPop},
		{"swap", montySwap},
		{"queue", montyQueue},
		{"stack", montyStack},
		{"add", montyAdd},
		{"nop", montyNop},
		{"sub", montySub},
		{"mul", montyMul},
		{"div", montyDiv},
		{"mod", montyMod},
		{"pchar", montyPchar},
		{"pstr", montyPstr},
		{"rotl", montyRotl},
		{"rotr", montyRotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opFunct[i].opcode; i++)
	{
		if (_strcmp(opFunct[i].opcode, key) == 0)
			break;
	}

	return (opFunct[i].f);
}
