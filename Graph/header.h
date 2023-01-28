#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0
#define VERTEX_MAX_SIZE           50
#define ADJ_VERTEX_STR_MAX_SIZE   50
#define TMP_STR_MAX_SIZE          50

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
void deleteEdge(Graph *graph, int start, int end);
void deleteVertex(Graph *graph, int vertex);
void printAdjMatrix(Graph *graph);
void adjacent(Graph *graph, int vertex);
