#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define VERTEX_MAX_SIZE    10

typedef struct Graph {
    int size;
    int adjMatrix[VERTEX_MAX_SIZE][VERTEX_MAX_SIZE];
} Graph;

Graph* create(void);
int isEmpty(Graph *graph);
int isFull(Graph *graph);
void insertVertex(Graph *graph, int vertex);
int isEdgeNumError(Graph *graph, int start, int end);
void insertEdge(Graph *graph, int start, int end);
void printAdjMatrix(Graph *graph);
void deleteEdge(Graph *graph, int start, int end);
void deleteVertex(Graph *graph, int vertex);
