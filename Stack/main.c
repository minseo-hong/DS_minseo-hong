#include "header.h"

int main(void) {
    Stack *stack = create();
    
    while (TRUE) {
        char command[COMMAND_MAX_SIZE];
        
        printf(">> ");
        
        scanf("%[^\n]", command);
        
        getchar();
        
        if (!strcmp(command, "END")) {
            break;
        }
        
        int printFlag = FALSE;
        
        int index = 0;
        
        while (command[index] != '\0') {
            switch (command[index]) {
                case '+':
                    index++;
                    
                    push(stack, command[index]);
                    
                    printFlag = TRUE;
                    
                    break;
                case '-':
                    pop(stack);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'L':
                    printFlag = TRUE;
                
                    break;
                case 'P':
                    printf("%c", peek(stack));
                
                    break;
                case 'F':
                    if (isFull(stack)) {
                        printf("TRUE");
                    } else {
                        printf("FALSE");
                    }
                    
                    break;
                case 'E':
                    if (isEmpty(stack)) {
                        printf("TRUE");
                    } else {
                        printf("FALSE");
                    }
                    
                    break;
                case 'T':
                    top(stack);
                    
                    break;
                case '#':
                    printf("%d", elementCount(stack));
                    
                    break;
                case '?':
                    index++;
                    
                    if (isMemeber(stack, command[index])) {
                        printf("TRUE");
                    } else {
                        printf("FALSE");
                    }
                    
                    break;
                case '=':
                    index++;
                    
                    replace(stack, command[index]);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'C':
                    stack = clearAll(stack);
                    
                    printFlag = TRUE;
                    
                    break;
            }
            
            index++;
        }
        
        if (printFlag) {
            printAll(stack);
        }
        
        printf("\n");
    }
    
    deleteAll(stack);
    
    return 0;
}

Stack* create(void) {
    Stack *stack = (Stack *)malloc(sizeof(stack));
    
    stack->top = -1;
    
    return stack;
}

int isFull(Stack *stack) {
    return (stack->top == STACK_MAX_SIZE - 1);
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

void push(Stack *stack, element value) {
    if (isFull(stack)) {
        printf("FULL\n");
        
        return ;
    }
    
    (stack->top)++;
    
    stack->data[stack->top] = value;
}

element pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("EMPTY\n");
        
        return '\0';
    }
    
    element result = stack->data[stack->top];
    
    (stack->top)--;
    
    return result;
}

element peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("EMPTY\n");
        
        exit(1);
    }
    
    return stack->data[stack->top];
}

void printAll(Stack *stack) {
    if (isEmpty(stack)) {
        printf("EMPTY");
        
        return ;
    }
    
    Stack *tmpStack = create();
    
    while (stack->top > -1) {
        push(tmpStack, pop(stack));
    }
    
    while (tmpStack->top > -1) {
        element value = pop(tmpStack);
        
        if (tmpStack->top == -1) {
            printf(">%c<", value);
        } else {
            printf("%c ", value);
        }
        
        push(stack, value);
    }
    
    deleteAll(tmpStack);
}

void top(Stack *stack) {
    printf("(%d, %c)", stack->top, peek(stack));
}

void replace(Stack *stack, element value) {
    pop(stack);
    push(stack, value);
}

int isMemeber(Stack *stack, element value) {
    return stack->data[stack->top] == value;
}

int elementCount(Stack *stack) {
    return stack->top + 1;
}

Stack* clearAll(Stack *stack) {
    deleteAll(stack);
    
    Stack *newStack = create();
    
    return newStack;
}

void deleteAll(Stack *stack) {
    free(stack);
}
