#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_MAX_SIZE  100

#define TRUE    1
#define FALSE   0

#define NULL_ELEMENT    '\0'

typedef int element;

typedef struct {
    element data[QUEUE_MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* create(void);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, element item);
element dequeue(Queue *queue);
element peek(Queue *queue);
void deleteAll(Queue *queue);
