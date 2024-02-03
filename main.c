#include "monty.h"

global_t global_info;

/**
 * release_global_info - frees the global variables
 */
void release_global_info(void)
{
	_new_free_dlistint(&(global_info.linked_list_head));
	free(global_info.input_buffer);
	fclose(global_info.file_descriptor);
}

/**
 * initialize_global_info - initializes the global variables
 * @file_desc: file descriptor
 */
void initialize_global_info(FILE *file_desc)
{
	global_info.lifo = 1;
	global_info.continue_execution = 1;
	global_info.argument_value = NULL;
	global_info.linked_list_head = NULL;
	global_info.file_descriptor = file_desc;
	global_info.input_buffer = NULL;
}

/**
 * check_and_open_file - checks if the file exists and if it can be opened
 * @argument_count: argument count
 * @argument_vector: argument vector
 * Return: file struct
 */
FILE *check_and_open_file(int argument_count, char *argument_vector[])
{
	FILE *file_desc;

	if (argument_count != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_desc = fopen(argument_vector[1], "r");

	if (file_desc == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argument_vector[1]);
		exit(EXIT_FAILURE);
	}

	return file_desc;
}

/**
 * main - Entry point
 * @argument_count: argument count
 * @argument_vector: argument vector
 * Return: 0 on success
 */
int main(int argument_count, char *argument_vector[])
{
	void (*opcode_function)(stack_t **stack, unsigned int line_number);
	FILE *file_desc;
	size_t buffer_size = 256;
	ssize_t read_lines = 0;
	char *line_tokens[2] = {NULL, NULL};

	file_desc = check_and_open_file(argument_count, argument_vector);
	initialize_global_info(file_desc);

	read_lines = getline(&(global_info.input_buffer), &buffer_size, file_desc);
	while (read_lines != -1)
	{
		line_tokens[0] = _strtoky(global_info.input_buffer, " \t\n");
		if (line_tokens[0] && line_tokens[0][0] != '#')
		{
			opcode_function = get_opcodes(line_tokens[0]);
			if (!opcode_function)
			{
				dprintf(2, "L%u: unknown instruction %s\n", global_info.continue_execution, line_tokens[0]);
				release_global_info();
				exit(EXIT_FAILURE);
			}
			global_info.argument_value = _strtoky(NULL, " \t\n");
			opcode_function(&(global_info.linked_list_head), global_info.continue_execution);
		}
		read_lines = getline(&(global_info.input_buffer), &buffer_size, file_desc);
		global_info.continue_execution++;
	}

	release_global_info();

	return 0;
}
