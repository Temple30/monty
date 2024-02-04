#include "monty.h"

/**
* main - monty code entry point
* @ac: number of arguments
* @argv: monty file path
* Return: 0 on success
*/

globeV varG = {NULL, NULL, NULL, 0};

int main(int ac, char *argv[])
{
    char *buffer;   
    FILE *f;      
    size_t bsize = 0; 
    ssize_t charNum = 1; 
    stack_t *temp = NULL; 
    unsigned int count = 0; 
    
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n"); 
        exit(EXIT_FAILURE); 
    }

    f = openFile(argv[1]);

    while (charNum != 0) 
    {
        buffer = NULL;

        charNum = getline(&buffer, &bsize, f);
        varG.theOps = buffer; 
        count++;

        if (charNum > 0)
        {
            callMethod(buffer, &temp, count, f); 
        }

        
        free(buffer);
    }

    freeDLL(temp);
    fclose(f);

    return (0);
}

