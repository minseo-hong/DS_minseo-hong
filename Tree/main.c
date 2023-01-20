#include "header.h"

int main(void) {
    Tree *tree = create();
    
    char command[COMMAND_MAX_SIZE];
    
    int cmdIndex;
    
    int newKey;
    
    
    while (TRUE) {
        command[0] = '\0';
        
        printf(">> ");
        scanf("%[^\n]", command);
        getchar();
        
        if (isCommandEnd(command)) {
            break;
        }
        
        cmdIndex = 0;
        
        while (command[cmdIndex] != '\0') {
            switch (command[cmdIndex]) {
                case '+':
                    newKey = convertCmdToInt(command, cmdIndex);
                    
                    insertNode(tree, newKey);
                    
                    break;
                case 'E':
                    if (isEmpty(tree)) {
                        printf("TRUE\n");
                    } else {
                        printf("FALSE\n");
                    }
                    
                    break;
                case 'C':
                    clearAll(tree);
                    
                    break;
            }
            
            cmdIndex++;
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
    
    int keyIndex = cmdIndex;
    
    char keyStr[KEY_STR_MAX_SIZE];
    char tmpStr[TMP_STR_MAX_SIZE];
    
    while (command[keyIndex] >= '0' && command[keyIndex] <= '9') {
        sprintf(tmpStr, "%c", command[keyIndex]);
        strcat(keyStr, tmpStr);
        
        keyIndex++;
    }
    
    key = atoi(keyStr);
    
    return key;
}

Tree* create(void) {
    Tree *newTree = (Tree *)malloc(sizeof(Tree));
    
    newTree->root = NULL;
    
    return newTree;
}

void insertNode(Tree *tree, element key) {
    _insertNode(tree->root, key);
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

int isEmpty(Tree *tree) {
    if (tree->root == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void clearAll(Tree *tree) {
    deleteAll(tree);
    
    tree = create();
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
