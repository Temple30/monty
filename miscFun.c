#include "monty.h"

/**
 * openFile - opens a file and assigns it to global variable
 * fileName: name of file to open
 * Return: file if success, NULL otherwise
 * */

FILE *openFile(const char *fileName)
{
FILE *file = fopen(fileName, "r");

if (file == NULL)
{
   fprintf(stderr, "Error: Can't open file %s\n", fileName);
   exit(EXIT_FAILURE);
 }
 varG.file = file;
 return file;
}
