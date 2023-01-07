#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_MAX_SIZE    100

#define COMMAND_MAX_SIZE  100

#define TRUE    1
#define FALSE   0

typedef char element;

typedef struct {
    int top;
    element data[STACK_MAX_SIZE];
} Stack;

Stack* create(void);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, element item);
element pop(Stack *stack);
element peek(Stack *stack);
void printAll(Stack *stack);
void top(Stack *stack);
void replace(Stack *stack, element item);
int isMemeber(Stack *stack, element item);
int elementCount(Stack *stack);
void clearAll(Stack *stack);
void deleteAll(Stack *stack);
