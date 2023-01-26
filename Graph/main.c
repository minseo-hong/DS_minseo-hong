#include <stdio.h>
#include <stdlib.h>

#define VERTEX_MAX_SIZE    100

#define TRUE    1
#define FALSE   0

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct Graph {
    int n;
    GraphNode *adjList[VERTEX_MAX_SIZE];
} Graph;

Graph* create(void);
int isFull(Graph *graph);
void insertVertex(Graph *graph, int v);
void printAdjList(Graph *graph);

int main(void) {
    Graph *graph = create();
    return 0;
}

Graph* create(void) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->n = 0;
    for (int i = 0; i < VERTEX_MAX_SIZE; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

int isFull(Graph *graph) {
    if ((graph->n + 1) > VERTEX_MAX_SIZE)
        return FALSE;
    return TRUE;
}

void insertVertex(Graph *graph, int vertex) {
    GraphNode *newNode;
    if (isFull(graph))
        return;
    newNode = (GraphNode *)malloc(sizeof(GraphNode));
    newNode->vertex = vertex;
    newNode->link = graph->adjList[graph->n];
    graph->adjList[graph->n] = newNode;
    graph->n++;
    
}

void insertEdge(Graph *graph, int start, int end) {
    int i;
    GraphNode *newNode;
    for (i = 0; i < graph->n; i++)
        if (graph->adjList[i]->vertex == start)
            break;
    newNode = (GraphNode *)malloc(sizeof(GraphNode));
    newNode->vertex = end;
    newNode->link = graph->adjList[i];
    graph->adjList[i] = newNode;
}

void printAdjList(Graph *graph) {
    int isFirst;
    GraphNode *currentNode;
    for (int i = 0; i < graph->n; i++) {
        isFirst = TRUE;
        currentNode = graph->adjList[i];
        while (currentNode != NULL) {
            if (isFirst) {
                printf("정점 %d", currentNode->vertex);
                isFirst = FALSE;
            } else {
                printf(" -> %d", currentNode->vertex);
            }
            currentNode = currentNode->link;
        }
        printf("\n");
    }
}
