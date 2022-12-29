#include "header.h"

int main(void) {
    LinkedList *list = NULL;
    
    list = create(list);
    
    while (TRUE) {
        char command[COMMAND_MAX_SIZE];
        
        printf(">> ");
        
        scanf("%[^\n]", command);
        
        getchar();
        
        if (strcmp(command, END_COMMAND) == STRCMP_EQUAL) {
            printf("END\n");
            
            break;
        }
        
        int printFlag = FALSE;
        
        int index = 0;
        
        while (command[index] != STR_NULL) {
            switch (command[index]) {
                case ADD_TAIL_COMMAND:
                    index += 1;
                    
                    addTail(list, command[index]);
                    
                    printFlag = TRUE;
                    
                    break;
                case DELETE_COMMAND:
                    if (isEmpty(list) == FALSE) {
                        deleteData(list);
                    }
                    
                    printFlag = TRUE;
                    
                    break;
                case PRINT_LIST_COMMAND:
                    printFlag = TRUE;
                    
                    break;
                case DATA_COUNT_COMMAND:
                    printf("%d\n", dataCount(list));
                    
                    break;
                case GET_DATA_COMMAND:
                    printf("%c (", getData(list));
                    
                    printList(list);
                    
                    printf(")\n");
                    
                    break;
                case IS_MEMBER_COMMAND:
                    index += 1;
                    
                    int elementIndex = isMember(list, command[index]);
                    
                    printf("%d: ", elementIndex);
                    
                    printFlag = TRUE;
                    
                    break;
                case CLEAR_LIST_COMMAND:
                    list = clearList(list);
                    
                    printf("CLEAR\n");
                    
                    break;
                case IS_EMPTY_COMMAND:
                    if (isEmpty(list)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
            }
            
            index += 1;
        }
        
        if (printFlag) {
            printList(list);
            
            printf("\n");
        }
    }
    
    deleteList(list);
    
    return 0;
}

LinkedList* create(LinkedList *list) {
    list = (LinkedList *)malloc(sizeof(LinkedList));
    
    list->head = (ListNode *)malloc(sizeof(ListNode));
    list->selected = list->head;
    
    return list;
}

void addTail(LinkedList *list, element value) {
    ListNode *lastNode = list->head;
    
    while (lastNode->link != NULL) {
        lastNode = lastNode->link;
    }
    
    ListNode *newNode = (ListNode *)malloc(sizeof(newNode));
    
    newNode->data = value;
    
    newNode->link = lastNode->link;
    lastNode->link = newNode;
    
    list->selected = newNode;
}

void deleteData(LinkedList *list) {
    ListNode *prevNode = list->head;
    
    while (prevNode->link != list->selected) {
        prevNode = prevNode->link;
    }
    
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
    ListNode *lastNode = list->head;
    
    while (lastNode->link != NULL) {
        lastNode = lastNode->link;
    }
    
    ListNode *curNode = list->head->link;
    
    if (isEmpty(list)) {
        printf("EMPTY");
    } else {
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
    
    list = create(list);
    
    return list;
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
