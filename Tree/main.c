#include "header.h"

int main(void) {
    Tree *tree = create();
    
    char command[COMMAND_MAX_SIZE];
    int cmdIndex, printFlag;
    
    element newKey, minKey, maxKey;
    
    while (TRUE) {
        cmdIndex = 0;
        command[cmdIndex] = '\0';
        printFlag = FALSE;
        
        printf(">> ");
        scanf("%[^\n]", command);
        getchar();
        
        if (isCommandEnd(command)) {
            break;
        }
        
        while (command[cmdIndex] != '\0') {
            switch (command[cmdIndex]) {
                case '+':
                    cmdIndex++;
                    newKey = convertCmdToInt(command, cmdIndex);
                    insertNode(tree, newKey);
                    
                    printFlag = TRUE;
                    
                    break;
                case 'L':
                    printFlag = TRUE;
                    
                    break;
                case 'N':
                    minKey = getMin(tree);
                    
                    if (minKey != NULL_INT) {
                        printf("%d\n", minKey);
                    }
                    
                    break;
                case 'M':
                    maxKey = getMax(tree);
                    
                    if (maxKey != NULL_INT) {
                        printf("%d\n", maxKey);
                    }
                    
                    break;
                case 'E':
                    if (isEmpty(tree)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'C':
                    tree = clearAll(tree);
                    
                    printFlag = TRUE;
                    
                    break;
            }
            
            cmdIndex++;
        }
        
        if (printFlag) {
            printAll(tree);
        }
    }
    
    deleteAll(tree);
    
    return 0;
}

int isCommandEnd(char *command) {
    char endContinue;
    
    if (!strcmp(command, "END")) {
        printf("Are you sure to quit this program? (Y/N) ");
        scanf("%c", &endContinue);
        getchar();
        
        if (endContinue == 'Y' || endContinue == 'y') {
            printf("\n");
            
            return TRUE;
        }
    }
    
    return FALSE;
}

int convertCmdToInt(char *command, int cmdIndex) {
    int key;
    char keyStr[KEY_STR_MAX_SIZE] = "";
    char tmpStr[TMP_STR_MAX_SIZE] = "";
    
    while (command[cmdIndex] >= '0' && command[cmdIndex] <= '9') {
        sprintf(tmpStr, "%c", command[cmdIndex]);
        strcat(keyStr, tmpStr);
        
        cmdIndex++;
    }
    
    key = atoi(keyStr);
    
    return key;
}

Tree* create(void) {
    Tree *newTree = (Tree *)malloc(sizeof(Tree));
    
    return newTree;
}

void insertNode(Tree *tree, element key) {
    if (tree->root == NULL) {
        tree->root = newNode(key);
    } else {
        _insertNode(tree->root, key);
    }
}

TreeNode* _insertNode(TreeNode *node, element key) {
    if (node == NULL) {
        return newNode(key);
    }
    
    if (key < node->key) {
        node->left = _insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = _insertNode(node->right, key);
    }
    
    return node;
}

TreeNode* newNode(element key) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void printAll(Tree *tree) {
    if (tree->root == NULL) {
        printf("-");
    } else {
        traversal(tree->root);
    }
    
    printf("\n");
}

void traversal(TreeNode *node) {
    if (node != NULL) {
        traversal(node->left);
        printf("%d ", node->key);
        traversal(node->right);
    }
}

element getMin(Tree *tree) {
    if (isEmpty(tree)) {
        printf("Error (tree is empty)\n");
        
        return NULL_INT;
    }
    
    return _getMin(tree->root);
}

element _getMin(TreeNode *node) {
    if (node->left == NULL) {
        return node->key;
    }
    
    return _getMin(node->left);
}

element getMax(Tree *tree) {
    if (isEmpty(tree)) {
        printf("Error (tree is empty)\n");
        
        return NULL_INT;
    }
    
    return _getMax(tree->root);
}

element _getMax(TreeNode *node) {
    if (node->right == NULL) {
        return node->key;
    }
    
    return _getMax(node->right);
}

int isEmpty(Tree *tree) {
    if (tree->root == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Tree* clearAll(Tree *tree) {
    deleteAll(tree);
    
    Tree *newTree = create();
    
    return newTree;
}

void deleteAll(Tree *tree) {
    deleteSubTree(tree->root);
    free(tree);
}

void deleteSubTree(TreeNode *node) {
    if (node != NULL) {
        deleteSubTree(node->left);
        deleteSubTree(node->right);
        free(node);
    }
}
