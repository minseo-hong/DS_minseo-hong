#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

#define COMMAND_MAX_SIZE    100

#define KEY_STR_MAX_SIZE    100
#define TMP_STR_MAX_SIZE    10

typedef int element;

typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
} Tree;

int isCommandEnd(char *command);
int convertCmdToInt(char *command, int cmdIndex);
Tree* create(void);
void insertNode(Tree *tree, element key);
TreeNode* _insertNode(TreeNode *node, element key);
TreeNode* newNode(element key);
void printAll(Tree *tree);
void traversal(TreeNode *node);
int isEmpty(Tree *tree);
Tree* clearAll(Tree *tree);
void deleteAll(Tree *tree);
void deleteSubTree(TreeNode *node);
