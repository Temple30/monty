#include "monty.h"

/**
 * select_opcode_function - selects the correct function for the opcode
 *
 * @requested_opcode: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*choose_opcode_function(char *requested_opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t available_instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int index;

	for (index = 0; available_instructions[index].opcode; index++)
	{
		if (_strcmp(available_instructions[index].opcode, requested_opcode) == 0)
			break;
	}

	return (available_instructions[index].f);
}
