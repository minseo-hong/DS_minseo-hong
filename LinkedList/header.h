#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

#define COMMAND_MAX_SIZE  50

#define NOT_FOUNDED  -1

typedef char element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

typedef struct LinkedList {
    ListNode *head;
    ListNode *selected;
} LinkedList;

LinkedList* create(void);
void addTail(LinkedList *list, element value);
void deleteData(LinkedList *list);
void printList(LinkedList *list);
int dataCount(LinkedList *list);
element getData(LinkedList *list);
int isMember(LinkedList *list, element value);
LinkedList* clearList(LinkedList *list);
int isEmpty(LinkedList *list);
void deleteList(LinkedList *list);
