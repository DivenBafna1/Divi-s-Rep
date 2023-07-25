#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue data structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph data structure
typedef struct {
    int vertexCount;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function prototypes
void initGraph(Graph* graph, int vertexCount);
void addEdge(Graph* graph, int src, int dest);
void bfs(Graph* graph, int startVertex);

// Queue operations
void initQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isQueueEmpty(Queue* q);

int main() {
    Graph graph;
    int vertexCount, edgeCount;
    int src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertexCount);

    initGraph(&graph, vertexCount);

    printf("Enter the number of edges: ");
    scanf("%d", &edgeCount);

    for (int i = 0; i < edgeCount; i++) {
        printf("Enter the source and destination vertex of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    int startVertex;
    printf("Enter the source vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(&graph, startVertex);

    return 0;
}

// Initialize the graph with vertexCount vertices
void initGraph(Graph* graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Add an edge between two vertices in the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    // If the graph is undirected, uncomment the following line to add the reverse edge
    // graph->adjacencyMatrix[dest][src] = 1;
}

// Breadth-First Search algorithm to find shortest path and distance
void bfs(Graph* graph, int startVertex) {
    Queue q;
    bool visited[MAX_VERTICES] = { false };
    int distance[MAX_VERTICES] = { 0 };

    initQueue(&q);
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertexCount; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[currentVertex] + 1;
                enqueue(&q, i);
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", startVertex);
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Remove and return the front element from the queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}
