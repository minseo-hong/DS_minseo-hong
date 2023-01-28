#include "header.h"

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
    deleteVertex(graph, 0);
    printf("Vertex 0 removed\n");
    printAdjMatrix(graph);
    return 0;
}

Graph* create(void) {
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->size = 0;
    for (int row = 0; row < VERTEX_MAX_SIZE; row++)
        for (int col = 0; col < VERTEX_MAX_SIZE; col++)
            newGraph->adjMatrix[row][col] = -1;
    return newGraph;
}

int isEmpty(Graph *graph) {
    return (graph->size == 0);
}

int isFull(Graph *graph) {
    return (graph->size == VERTEX_MAX_SIZE);
}

int isEdgeNumError(Graph *graph, int start, int end) {
    return (start > graph->size || end > graph->size);
}

void insertVertex(Graph *graph, int vertex) {
    if (isFull(graph)) return;
    graph->size++;
    for (int i = 0; i < graph->size; i++) {
        graph->adjMatrix[vertex][i] = 0;
        graph->adjMatrix[i][vertex] = 0;
    }
    
}

void insertEdge(Graph *graph, int start, int end) {
    if (isEdgeNumError(graph, start, end)) return;
    graph->adjMatrix[start][end] = 1;
    graph->adjMatrix[end][start] = 1;
}

void deleteVertex(Graph *graph, int vertex) {
    if (isEmpty(graph)) return;
    for (int i = 0; i < graph->size; i++) {
        graph->adjMatrix[vertex][i] = -1;
        graph->adjMatrix[i][vertex] = -1;
    }
    graph->size--;
}

void deleteEdge(Graph *graph, int start, int end) {
    if (isEdgeNumError(graph, start, end)) return;
    graph->adjMatrix[start][end] = 0;
    graph->adjMatrix[end][start] = 0;
}

void printAdjMatrix(Graph *graph) {
    int isEmptyRow;
    for (int row = 0; row < VERTEX_MAX_SIZE; row++) {
        isEmptyRow = TRUE;
        for (int col = 0; col < VERTEX_MAX_SIZE; col++) {
            if (graph->adjMatrix[row][col] != -1) {
                printf("%d ", graph->adjMatrix[row][col]);
                isEmptyRow = FALSE;
            }
        }
        if (!isEmptyRow) printf("\n");
    }
}
