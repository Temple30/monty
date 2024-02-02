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
		{"push", _new_push},
		{"pall", _new_pall},
		{"pint", _new_pint},
		{"pop", _new_pop},
		{"swap", _new_swap},
		{"queue", _new_queue},
		{"stack", _new_stack},
		{"add", _new_add},
		{"nop", _new_nop},
		{"sub", _new_sub},
		{"mul", _new_mul},
		{"div", _new_div},
		{"mod", _new_mod},
		{"pchar", _new_pchar},
		{"pstr", _new_pstr},
		{"rotl", _new_rotl},
		{"rotr", _new_rotr},
		{NULL, NULL}
	};
	int index;

	for (index = 0; available_instructions[index].opcode; index++)
	{
		if (_new_strcmp(available_instructions[index].opcode, requested_opcode) == 0)
			break;
	}

	return (available_instructions[index].f);
}
