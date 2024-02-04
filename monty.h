#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
	char *argument_value;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void customAdd(stack_t **stackHead, unsigned int lineNumber);
void free_stack(stack_t *head);

void customDivide(stack_t **stackHead, unsigned int lineNumber);
int performOperation(char *lineContent, stack_t **stack, unsigned int lineNumber, FILE *montyFile);
void customModulo(stack_t **stackHead, unsigned int lineNumber);
void customMultiply(stack_t **stackHead, unsigned int lineNumber);
void addToStack(stack_t **stackHead, int value);
void customNoOperation(stack_t **stackHead, unsigned int lineNumber);
void customPrintAll(stack_t **stackHead, unsigned int lineNumber);
void customPrintChar(stack_t **stackHead, unsigned int lineNumber);
void customPrintTopValue(stack_t **stackHead, unsigned int lineNumber);
void customPop(stack_t **stackHead, unsigned int lineNumber);
void customPrintString(stack_t **stackHead, unsigned int lineNumber);
void customPush(stack_t **stackHead, unsigned int lineNumber);
void customQueueMode(stack_t **stackHead, unsigned int lineNumber);
void addToQueue(stack_t **stackHead, int value);
void customRotateLeft(stack_t **stackHead,  __attribute__((unused)) unsigned int lineNumber);
void customRotateRight(stack_t **stackHead, __attribute__((unused)) unsigned int lineNumber);
void customPrintTop(stack_t **stackHead, unsigned int lineNumber);
void customFreeStack(stack_t *stackHead);
void customSubtraction(stack_t **stackHead, unsigned int lineNumber);
void customSwap(stack_t **stackHead, unsigned int lineNumber);

#endif
