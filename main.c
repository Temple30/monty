#define _POSIX_C_SOURCE 200809L
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0, NULL};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])

{
    char *line_content;
    FILE *monty_file;
    size_t buffer_size = 0;
    ssize_t read_lines = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    bus.file = monty_file;

    if (!monty_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_lines > 0)
    {
        line_content = NULL;
        read_lines = getline(&line_content, &buffer_size, monty_file);
        bus.content = line_content;
        line_number++;

        if (read_lines > 0)
        {
            execle(line_content, line_content, &stack, &line_number, monty_file, NULL,NULL);
        }

        free(line_content);
    }

    free_stack(stack);
    fclose(monty_file);

    return (EXIT_SUCCESS);
}
