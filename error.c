#include "monty.h"

/**
 * print_to_stdout - Prints a message to the standard output.
 * @message: The message to be printed.
 *
 * Description: This function prints the
 * specified message to the standard output.
 * It is used for providing information about the success of operations.
 */
void print_to_stdout(const char *message)
{
	printf("%s", message);
}

/**
 * print_to_stderr - Prints an error message to the standard error.
 * @error_message: The error message to be printed.
 *
 * Description: This function prints the
 * specified error message to the standard error.
 * It is used for reporting errors or failures in operations.
 */
void print_to_stderr(const char *error_message)
{
	fprintf(stderr, "%s", error_message);
}
