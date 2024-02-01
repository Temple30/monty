#include "monty.h"

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int lNum);
	FILE *fptr;
	size_t size;
	ssize_t numChar;

	char *word[2] = {NULL, NULL};

	size = 65;
	numChar = 0;

	fptr = fValidate(argc, argv);

	startvarG(fptr);

	numChar = getline(&varG.buffer, &size, fptr);
	while (numChar != -1)
	{
		word[0] = _strtoky(varG.buffer, " \t\n");
		if (word[0])
		{
			f = callMethod(word[0]);

			if (f == NULL)
			{
				dprintf(2, "L%u: ", varG.count);
				dprintf(2, "unknown instruction %s\n", word[0]);
				varG();
				exit(EXIT_FAILURE);
			}
			varG.arg = _strtoky(NULL, " \t\n");
			f(&varG.head, varG.count);
		}
		numChar = getline(&varG.buffer, &size, fptr);
		varG.count++;
	}

	freevarG();

	return (0);
}

globals varG;

/**
 * freevarG - frees all global variables
 *
 * Return: no return
 */
void freevarG(void)
{
	freeDLL(varG.head);
	free(varG.buffer);
	fclose(varG.fptr);
}

/**
 * startvarG - initializes all global variables
 *
 * @fptr: file descriptor
 * Return: no return
 */
void startvarG(FILE *fptr)
{
	varG.fptr = fptr;
	varG.arg = NULL;
	varG.buffer = NULL;
	varG.head = NULL;
	varG.count = 1;
	varG.islifo = 1;
}

/**
 * fValidate - checks if the file exists and if file opens
 *
 * @argc: arg count
 * @argv: arg vector
 * Return: pointer
 */
FILE *fValidate(int argc, char *argv[])
{
	FILE *fptr;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");

	if (fptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fptr);
}

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 on success
 */
