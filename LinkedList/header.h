#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

#define COMMAND_MAX_SIZE  50

#define STR_NULL  '\0'

#define STRCMP_EQUAL  0

#define NOT_FOUNDED  -1

#define ADD_TAIL_COMMAND     '+'
#define DELETE_COMMAND       '-'
#define PRINT_LIST_COMMAND   'L'
#define DATA_COUNT_COMMAND   '#'
#define GET_DATA_COMMAND     'G'
#define IS_MEMBER_COMMAND    '?'
#define CLEAR_LIST_COMMAND   'C'
#define IS_EMPTY_COMMAND     'E'

#define END_COMMAND         "END"

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
