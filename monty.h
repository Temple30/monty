#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globeV - variables made available globally
 * @data: value being read
 * @file: pointer to monty file
 * @theOps: line content
 * @stackQ: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct globalVariables
{
	char *data;
	FILE *file;
	char *theOps;
	int stackQ;
}  globeV;
extern globeV varG;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void mush(stack_t **dlhead, unsigned int lNum);
void mall(stack_t **dlhead, unsigned int lNum);
void mint(stack_t **dlhead, unsigned int lNum);
int callMethod(char *theOps, stack_t **dlhead, unsigned int counter, FILE *file);
void freeExit(stack_t **head, int exit_code);
void freeDLL(stack_t *dlhead);
void mop(stack_t **dlhead, unsigned int count);
void montywap(stack_t **dlhead, unsigned int count);
void madd(stack_t **dlhead, unsigned int count);
void nope(stack_t **dlhead, unsigned int count);
void nodeNew(stack_t **head, int n);
void queueNew(stack_t **head, int n);
FILE *openFile(const char *filename);

#endif

