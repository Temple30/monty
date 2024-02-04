#include "monty.h"

/**
* execute - executes the opcode
* @head: pointer to the stack
* @count: line number
* @file: pointer to file
* @theOps: line with key
* Return: nothing
*/

int callMethod(char *theOps, stack_t **head, unsigned int count, FILE *file)
{
    
	instruction_t key[] = {
				{"push", mush},
                {"pall", mall},
                {"pint", mint},
                {"pop", mop},
                {"swap", montywap},
				{"add", madd},
				{"nop", nope},
				};

	unsigned int i;
	char *tok = strtok(theOps, " \n\t");
	varG.data = strtok(NULL, " \n\t");
	 varG.file = file;
	  
	if (tok != NULL && tok[0] == '#')
		return (0);

	for(i = 0; key[i].opcode; i++)
	{
		if (strcmp(tok, key[i].opcode) == 0)
		{	key[i].f(head, count);
			return (0);
		}
	}
	if (tok != NULL && key[i].opcode == NULL)
	{
	       	fprintf(stderr, "L%d: unknown instruction %s\n", count, tok);
		freeExit(head,EXIT_FAILURE);
	}	

	return (1);
	}
