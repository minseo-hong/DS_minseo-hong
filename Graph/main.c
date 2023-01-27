#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define VERTEX_MAX_SIZE    100

typedef struct GraphNode {
    int vertexName;
    struct GraphNode *nextNode;
} GraphNode;

typedef struct Graph {
    int vertexCount;
    GraphNode *headerVertexGroup[VERTEX_MAX_SIZE];
} Graph;

Graph* create(void);
int isFull(Graph *graph);
void insertVertex(Graph *graph, int newVertexName);
void insertEdge(Graph *graph, int start, int end);
void swapAndInsertEdge(Graph *graph, int startVertexName, int endVertexName);
void printGraphAdjList(Graph *graph);

int isFirstInsertEdge = TRUE; // 간선 추가 함수를 1번만 재귀호출하기 위한 플래그

int main(void) {
    Graph *graph = create();
    return 0;
}

Graph* create(void) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->vertexCount = 0;
    for (int i = 0; i < VERTEX_MAX_SIZE; i++) {
        newGraph->headerVertexGroup[i] = NULL;
    }
    return newGraph;
}

int isEmpty(Graph *graph) {
    return graph->vertexCount == 0;
}

int isFull(Graph *graph) {
    return graph->vertexCount >= VERTEX_MAX_SIZE;
}

void insertVertex(Graph *graph, int newVertexName) {
    int newVertexIndex = graph->vertexCount;
    GraphNode *newVertex;
    if (isFull(graph))
        return;
    newVertex = (GraphNode *)malloc(sizeof(GraphNode));
    newVertex->vertexName = newVertexName;
    newVertex->nextNode = graph->headerVertexGroup[newVertexIndex];
    graph->headerVertexGroup[newVertexIndex] = newVertex;
    graph->vertexCount++;
}

void insertEdge(Graph *graph, int startVertexName, int endVertexName) {
    int searchedVertexIndex = 0;
    GraphNode *newEdgeVertex;
    for (int i = 0; i < graph->vertexCount; i++) {
        if (graph->headerVertexGroup[i]->vertexName == startVertexName) {
            searchedVertexIndex = i;
            break;
        }
    }
    newEdgeVertex = (GraphNode *)malloc(sizeof(GraphNode));
    newEdgeVertex->vertexName = endVertexName;
    newEdgeVertex->nextNode = graph->headerVertexGroup[searchedVertexIndex];
    graph->headerVertexGroup[searchedVertexIndex] = newEdgeVertex;
    if (isFirstInsertEdge) {
        isFirstInsertEdge = FALSE;
        swapAndInsertEdge(graph, startVertexName, endVertexName);
    } else {
        isFirstInsertEdge = TRUE;
    }
}

void swapAndInsertEdge(Graph *graph, int startVertexName, int endVertexName) {
    insertEdge(graph, endVertexName, startVertexName);
}

void printGraphAdjList(Graph *graph) {
    int isFirst;
    GraphNode *currentNode;
    for (int i = 0; i < graph->vertexCount; i++) {
        currentNode = graph->headerVertexGroup[i];
        isFirst = TRUE;
        while (currentNode != NULL) {
            if (isFirst) {
                printf("정점 %d", currentNode->vertexName);
                isFirst = FALSE;
            } else {
                printf(" -> %d", currentNode->vertexName);
            }
            currentNode = currentNode->nextNode;
        }
        printf("\n");
    }
}
