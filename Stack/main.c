#include "header.h"

int main(void) {
    Stack *stack = create();
    
    char command[COMMAND_MAX_SIZE];
    
    while (TRUE) {
        for (int i = 0; i < COMMAND_MAX_SIZE; i++) {
            command[i] = '\0';
        }
        
        printf(">> ");
        
        scanf("%[^\n]", command);
        
        getchar();
        
        if (!strcmp(command, "END")) {
            printf("Are you sure to end this program? (Y/N) ");
            
            char endCommand;
            
            scanf("%c", &endCommand);
            
            getchar();
            
            if (endCommand == 'Y' || endCommand == 'y') {
                printf("\n");
                
                break;
            } else {
                continue;
            }
        }
        
        int printFlag = FALSE;
        
        int index = 0;
        
        while (command[index] != '\0') {
            int popIter = 0;
            
            while (isdigit(command[index])) {
                popIter = popIter * 10 + (command[index] - '0');
                
                index++;
            }
            
            switch (command[index]) {
                case '+':
                    if (!isFull(stack)) {
                        printFlag = TRUE;
                    }
                    
                    index++;
                    
                    push(stack, command[index]);
                    
                    break;
                case '-':
                    if (!isEmpty(stack)) {
                        printFlag = TRUE;
                    }
                    
                    if (popIter) {
                        for (int n = 1; n <= popIter; n++) {
                            pop(stack);
                        }
                        
                        index++;
                    } else {
                        while (command[index] == '-') {
                            pop(stack);
                            
                            index++;
                        }
                    }
                    
                    break;
                case 'L':
                    printFlag = TRUE;
                
                    break;
                case 'P':
                    printf("%c\n", peek(stack));
                
                    break;
                case 'F':
                    if (isFull(stack)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'E':
                    if (isEmpty(stack)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'T':
                    top(stack);
                    
                    break;
                case '#':
                    printf("%d\n", elementCount(stack));
                    
                    break;
                case '?':
                    index++;
                    
                    if (isMemeber(stack, command[index])) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case '=':
                    index++;
                    
                    replace(stack, command[index]);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'C':
                    clearAll(stack);
                    
                    printFlag = TRUE;
                    
                    break;
            }
            
            index++;
        }
        
        if (printFlag) {
            printAll(stack);
        }
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

void push(Stack *stack, element item) {
    if (isFull(stack)) {
        printf("Error (no space to push)\n");
        
        return ;
    }
    
    (stack->top)++;
    
    stack->data[stack->top] = item;
}

element pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error (nothing to pop)\n");
        
        return '\0';
    }
    
    element result = stack->data[stack->top];
    
    (stack->top)--;
    
    return result;
}

element peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error (nothing to peek)\n");
        
        return '\0';
    }
    
    return stack->data[stack->top];
}

void printAll(Stack *stack) {
    if (isEmpty(stack)) {
        printf("-\n");
        
        return ;
    }
    
    Stack *tmpStack = create();
    
    while (stack->top > -1) {
        push(tmpStack, pop(stack));
    }
    
    while (tmpStack->top > -1) {
        element value = pop(tmpStack);
        
        if (tmpStack->top == -1) {
            printf(">%c<\n", value);
        } else {
            printf("%c ", value);
        }
        
        push(stack, value);
    }
    
    deleteAll(tmpStack);
}

void top(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Error (nothing to get with top)\n");
        
        return ;
    }
    
    printf("(%d, %c)\n", stack->top + 1, peek(stack));
}

void replace(Stack *stack, element item) {
    pop(stack);
    push(stack, item);
}

int isMemeber(Stack *stack, element item) {
    int isMember = FALSE;
    
    Stack *tmpStack = create();
    
    while (stack->top != -1) {
        if (peek(stack) == item) {
            isMember = TRUE;
        }
        
        push(tmpStack, pop(stack));
    }
    
    while (tmpStack->top != -1) {
        push(stack, pop(tmpStack));
    }
    
    return isMember;
}

int elementCount(Stack *stack) {
    return stack->top + 1;
}

void clearAll(Stack *stack) {
    while (stack->top > -1) {
        pop(stack);
    }
}

void deleteAll(Stack *stack) {
    free(stack);
}
