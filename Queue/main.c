#include "header.h"

int main(void) {
    Queue *queue = create();
    
    char command[STR_MAX_SIZE];
    
    int i, cmdIndex;
    
    char endContinue;
    
    int printFlag;
    
    char popResult[STR_MAX_SIZE];
    char tmpStr[STR_MAX_SIZE];
    
    while (TRUE) {
        command[0] = '\0';
        
        printf(">> ");
        scanf("%[^\n]", command);
        getchar();
        
        if (!strcmp(command, "END")) {
            printf("Are you sure to end this program? (Y/N) ");
            scanf("%c", &endContinue);
            getchar();
            
            if (endContinue == 'Y' || endContinue == 'y') {
                printf("\n");
                
                break;
            } else {
                continue;
            }
        }
        
        cmdIndex = 0;
        
        popResult[0] = '\0';
        tmpStr[0] = '\0';
        
        printFlag = FALSE;
        
        while (command[cmdIndex] != '\0') {
            switch (command[cmdIndex]) {
                case '+':
                    cmdIndex++;
                    
                    enqueue(queue, command[cmdIndex]);
                    
                    printFlag = TRUE;
                    
                    break;
                case '-':
                    sprintf(tmpStr, " %c", dequeue(queue));
                    strcat(popResult, tmpStr);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'F':
                    if (isFull(queue)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'E':
                    if (isEmpty(queue)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'P':
                    printf("%c\n", peek(queue));
                    
                    break;
                case 'L':
                    printFlag = TRUE;
                    
                    break;
                case '#':
                    printf("%d\n", elementCount(queue));
                    
                    break;
                case '?':
                    cmdIndex++;
                    
                    if (isMember(queue, command[cmdIndex])) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'C':
                    clearAll(queue);
                    
                    printFlag = TRUE;
                    
                    break;
            }
            
            cmdIndex++;
        }
        
        if (strcmp(popResult, "")) {
            printf("return");
            printf("%s\n", popResult);
        }
        
        if (printFlag) {
            printAll(queue);
        }
    }
    
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
    if (isEmpty(queue)) {
        printf("-\n");
        
        return ;
    }
    
    int i = queue->front;
    
    int isFirst = TRUE;
    
    while (TRUE) {
        i = (i + 1) % QUEUE_MAX_SIZE;
        
        if (isFirst) {
            printf(">%c<", queue->data[i]);
            
            isFirst = FALSE;
        } else {
            printf(" %c", queue->data[i]);
        }
        
        if (i == queue->rear) {
            printf("\n");
            
            break;
        }
    }
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
