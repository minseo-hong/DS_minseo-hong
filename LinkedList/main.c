#include "header.h"

int main(void) {
    LinkedList *list = create();
    
    while (TRUE) {
        char command[COMMAND_MAX_SIZE];
        
        printf(">> ");
        
        scanf("%[^\n]", command);
        
        getchar();
        
        if (!strcmp(command, "END")) {
            printf("END\n");
            
            break;
        }
        
        int printFlag = FALSE;
        int bracketFlag = FALSE;
        
        int index = 0;
        
        while (command[index] != '\0') {
            switch (command[index]) {
                case '+':
                    index++;
                    
                    addTail(list, command[index]);
                    
                    printFlag = TRUE;
                    
                    break;
                case '-':
                    deleteData(list);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'L':
                    printFlag = TRUE;
                    
                    break;
                case '#':
                    printf("%d\n", dataCount(list));
                    
                    break;
                case 'G':
                    printf("%c ", getData(list));
                    
                    printFlag = TRUE;
                    bracketFlag = TRUE;
                    
                    break;
                case '?':
                    index++;
                    
                    int elementOrder = isMember(list, command[index]);
                    
                    printf("%d: ", elementOrder);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'C':
                    list = clearList(list);
                    
                    printf("CLEAR\n");
                    
                    break;
                case 'E':
                    if (isEmpty(list)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
            }
            
            index++;
        }
        
        if (bracketFlag) {
            printf("(");
        }
        
        if (printFlag) {
            printList(list);
            
            if (!bracketFlag) {
                printf("\n");
            }
        }
        
        if (bracketFlag) {
            printf(")\n");
        }
    }
    
    deleteList(list);
    
    return 0;
}

LinkedList* create(void) {
    LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));
    
    newList->head = (ListNode *)malloc(sizeof(ListNode));
    newList->selected = newList->head;
    
    return newList;
}

void addTail(LinkedList *list, element value) {
    ListNode *node = list->head;
    
    while (node->link != NULL) {
        node = node->link;
    }
    
    ListNode *lastNode = node;
    
    ListNode *newNode = (ListNode *)malloc(sizeof(newNode));
    
    newNode->data = value;
    
    newNode->link = lastNode->link;
    lastNode->link = newNode;
    
    list->selected = newNode;
}

void deleteData(LinkedList *list) {
    if (isEmpty(list)) {
        return ;
    }
    
    ListNode *node = list->head;
    
    while (node->link != list->selected) {
        node = node->link;
    }
    
    ListNode *prevNode = node;
    
    if (list->selected->link == NULL) {
        prevNode->link = NULL;
        
        free(list->selected);
        
        list->selected = prevNode;
    } else {
        prevNode->link = list->selected->link;
        
        free(list->selected);
        
        list->selected = prevNode->link;
    }
    
}

void printList(LinkedList *list) {
    ListNode *node = list->head;
    
    while (node->link != NULL) {
        node = node->link;
    }
    
    ListNode *lastNode = node;
    
    ListNode *curNode = list->head->link;
    
    if (isEmpty(list)) {
        printf("EMPTY");
        
        return ;
    }
        
    while (curNode != NULL) {
        if (curNode == list->selected) {
            printf(">%c<", curNode->data);
        } else {
            printf("%c", curNode->data);
        }
        
        if (curNode != lastNode) {
            printf(" ");
        }
        
        curNode = curNode->link;
    }
}

int dataCount(LinkedList *list) {
    int count = 0;
    
    ListNode *curNode = list->head->link;
    
    while (curNode != NULL) {
        count++;
        
        curNode = curNode->link;
    }
    
    return count;
}

element getData(LinkedList *list) {
    return list->selected->data;
}

int isMember(LinkedList *list, element value) {
    ListNode *curNode = list->head->link;
    
    for (int index = 0; curNode != NULL; index++) {
        if (curNode->data == value) {
            list->selected = curNode;
            
            return index + 1;
        }
        
        curNode = curNode->link;
    }
    
    return NOT_FOUNDED;
}

LinkedList* clearList(LinkedList *list) {
    deleteList(list);
    
    LinkedList *newList = create();
    
    return newList;
}

int isEmpty(LinkedList *list) {
    if (list->head->link == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void deleteList(LinkedList *list) {
    ListNode *curNode = list->head;
    
    while (curNode != NULL) {
        ListNode *next = curNode->link;
        
        free(curNode);
        
        curNode = next;
    }
    
    free(list);
}
