#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

typedef struct Graph Graph;

void initializeGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }
}

void DFS(Graph* graph, int current, int destination, int visited[], int path[], int* foundPath) {
    if (current == destination) {
        *foundPath = 1;
        path[current] = 1;
        return;
    }

    visited[current] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[current][i] == 1 && !visited[i]) {
            path[i] = 1;
            DFS(graph, i, destination, visited, path, foundPath);
            if (*foundPath)
                return;
            path[i] = 0;
        }
    }
}

void findPath(Graph* graph, int source, int destination) {
    int visited[MAX_VERTICES] = {0};
    int path[MAX_VERTICES] = {0};
    int foundPath = 0;

    path[source] = 1;
    DFS(graph, source, destination, visited, path, &foundPath);

    if (foundPath) {
        printf("Path from %d to %d: ", source, destination);
        for (int i = 0; i < graph->numVertices; i++) {
            if (path[i])
                printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("No path from %d to %d.\n", source, destination);
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph graph;
    initializeGraph(&graph, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int src, dest;
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    int source, destination;
    printf("Enter the source and destination nodes: ");
    scanf("%d %d", &source, &destination);

    findPath(&graph, source, destination);

    return 0;
}
