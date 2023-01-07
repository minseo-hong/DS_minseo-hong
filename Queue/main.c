#include "header.h"

int main(void) {
    Queue *queue = create();
    
    printf("isEmpty? %d\n", isEmpty(queue));
    
    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    
    printf("Element Added\n");
    
    printf("Elment Count %d\n", elementCount(queue));
    
    printAll(queue);
    
    printf("isEmpty? %d\n", isEmpty(queue));
    
    printf("peek %c\n", peek(queue));
    
    printf("dequeue %c\n", dequeue(queue));
    printf("dequeue %c\n", dequeue(queue));
    printf("dequeue %c\n", dequeue(queue));
    
    deleteAll(queue);
    
    return 0;
}

Queue* create(void) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    
    queue->front = 0;
    queue->rear = 0;
    
    return queue;
}

int isFull(Queue *queue) {
    return ((queue->rear + 1) % QUEUE_MAX_SIZE == queue->front);
}

int isEmpty(Queue *queue) {
    return (queue->front == queue->rear);
}

void enqueue(Queue *queue, element item) {
    if (isFull(queue)) {
        printf("Error (no space to enqueue)\n");
        
        return ;
    }
    
    queue->rear = (queue->rear + 1) % QUEUE_MAX_SIZE;
    
    queue->data[queue->rear] = item;
}

element dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error (nothing to dequeue)\n");
        
        return NULL_ELEMENT;
    }
    
    queue->front = (queue->front + 1) % QUEUE_MAX_SIZE;
    
    return queue->data[queue->front];
}

element peek(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error (nothing to peek)\n");
        
        return NULL_ELEMENT;
    }
    
    return queue->data[(queue->front + 1) % QUEUE_MAX_SIZE];
}

void printAll(Queue *queue) {
    Queue *tmpQueue = create();
    
    if (isEmpty(queue)) {
        printf("-\n");
        
        return ;
    }
    
    while (!isEmpty(queue)) {
        enqueue(tmpQueue, dequeue(queue));
    }
    
    while (!isEmpty(tmpQueue)) {
        element item = dequeue(tmpQueue);
        
        if (isEmpty(tmpQueue)) {
            printf(">%c<\n", item);
        } else {
            printf("%c ", item);
        }
        
        enqueue(queue, item);
    }
    
    deleteAll(tmpQueue);
}

int elementCount(Queue *queue) {
    int count;
    
    if (queue->front <= queue->rear) {
        count = queue->rear - queue->front;
    } else {
        count = QUEUE_MAX_SIZE + (queue->rear - queue->front);
    }
    
    return count;
}

int isMember(Queue *queue, element item) {
    int isMember = FALSE;
    
    Queue *tmpQueue = create();
    
    while (!isEmpty(queue)) {
        if (peek(queue) == item) {
            isMember = TRUE;
        }
        
        enqueue(tmpQueue, dequeue(queue));
    }
    
    while (!isEmpty(tmpQueue)) {
        enqueue(queue, dequeue(tmpQueue));
    }
    
    return isMember;
}

void clearAll(Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

void deleteAll(Queue *queue) {
    free(queue);
}
