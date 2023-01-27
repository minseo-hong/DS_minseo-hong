#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0
#define VERTEX_MAX_SIZE    50

typedef struct Graph {
    int size;
    int adjMatrix[VERTEX_MAX_SIZE][VERTEX_MAX_SIZE];
} Graph;

Graph* create(void);
int isEmpty(Graph *graph);
int isFull(Graph *graph);
void insertVertex(Graph *graph, int vertex);
int isVertexNumError(Graph *graph, int start, int end);
void insertEdge(Graph *graph, int start, int end);
void printAdjMatrix(Graph *graph);
void deleteEdge(Graph *graph, int start, int end);

int main(void) {
    Graph *graph = create();
    printf("isEmpty : %d, isFull : %d\n", isEmpty(graph), isFull(graph));
    insertVertex(graph, 0);
    printf("Vertex 0 added\n");
    printf("isEmpty : %d, isFull : %d\n", isEmpty(graph), isFull(graph));
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    printf("Vertex 1, 2 added\n");
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    printf("Edge with Vertex 0 and 1 added\n");
    printf("Edge with Vertex 1 and 2 added\n");
    printAdjMatrix(graph);
    deleteEdge(graph, 0, 1);
    printf("Edge with Vertex 0 and 1 removed\n");
    printAdjMatrix(graph);
    return 0;
}

Graph* create(void) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->size = 0;
    for (int row = 0; row < VERTEX_MAX_SIZE; row++)
        for (int col = 0; col < VERTEX_MAX_SIZE; col++)
            newGraph->adjMatrix[row][col] = 0;
    return newGraph;
}

int isEmpty(Graph *graph) {
    return (graph->size == 0);
}

int isFull(Graph *graph) {
    return ((graph->size + 1) > VERTEX_MAX_SIZE);
}

int isVertexNumError(Graph *graph, int start, int end) {
    return (start > graph->size || end > graph->size);
}

void insertVertex(Graph *graph, int vertex) {
    if (isFull(graph))
        return;
    graph->size++;
}

void insertEdge(Graph *graph, int start, int end) {
    if (isVertexNumError(graph, start, end))
        return;
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void printAdjMatrix(Graph *graph) {
    for (int row = 0; row < graph->size; row++) {
        for (int col = 0; col < graph->size; col++)
            printf("%d ", graph->adjMatrix[row][col]);
        printf("\n");
    }
}

void deleteEdge(Graph *graph, int start, int end) {
    if (isVertexNumError(graph, start, end)) {
        return;
    }
    graph->adjMatrix[start][end] = 0;
    graph->adjMatrix[end][start] = 0;
}
