#include "header.h"

int main(void) {
    Graph *graph = create();
    
    // 정점 0 추가 후, isEmpty와 isFull 확인
    printf("isEmpty : %d, isFull : %d\n", isEmpty(graph), isFull(graph));
    insertVertex(graph, 0);
    printf("Add vertex 0\n");
    printf("isEmpty : %d, isFull : %d\n", isEmpty(graph), isFull(graph));
    printf("\n");

    // 정점 1과 정점 2 추가 후, 인접 행렬 출력
    insertVertex(graph, 1);
    insertVertex(graph, 2);
    printf("Add vertex 1 and vertex 2\n");
    printAdjMatrix(graph);
    printf("\n");
    
    // 간선 0-1과 간선 1-2 추가 후, 인접 행렬 출력
    insertEdge(graph, 0, 1);
    insertEdge(graph, 1, 2);
    printf("Add an edge with vertex 0 and vertex 1\n");
    printf("Add an edge with vertex 1 and vertex 2\n");
    printAdjMatrix(graph);
    printf("\n");
    
    // 정점 1에 인접한 모든 정점을 출력
    adjacent(graph, 1);
    printf("\n");
    
    // 각 정점에 인접한 모든 정점을 출력
    adjacent(graph, 0);
    adjacent(graph, 1);
    adjacent(graph, 2);
    printf("\n");
    
    // 간선 0-1 삭제 후, 인접 행렬 출력
    deleteEdge(graph, 0, 1);
    printf("Remove an edge with vertex 0 and vertex 1\n");
    printAdjMatrix(graph);
    printf("\n");
    
    // 정점 0 삭제 후, 인접 행렬 출력
    deleteVertex(graph, 0);
    printf("Remove vertex 0\n");
    printAdjMatrix(graph);
    printf("\n");
    
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

void adjacent(Graph *graph, int vertex) {
    int isEmptyRow = TRUE;
    char adjVertexStr[ADJ_VERTEX_STR_MAX_SIZE];
    char tmpStr[TMP_STR_MAX_SIZE];
    for (int i = 0; i < VERTEX_MAX_SIZE; i++)
        if (graph->adjMatrix[vertex][i] == 1) {
            isEmptyRow = FALSE;
            sprintf(tmpStr, " -> %d", i);
            strcat(adjVertexStr, tmpStr);
        }
    if (!isEmptyRow) {
        printf("Vertex %d", vertex);
        printf("%s", adjVertexStr);
        printf("\n");
    }
}
