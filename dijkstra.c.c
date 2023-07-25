#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INFINITY 9999
#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int distance[MAX_NODES];
bool visited[MAX_NODES];
int numNodes;

int getClosestNode() {
    int minDistance = INFINITY;
    int closestNode;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i] && distance[i] <= minDistance) {
            minDistance = distance[i];
            closestNode = i;
        }
    }

    return closestNode;
}

void dijkstra(int startNode) {
    for (int i = 0; i < numNodes; i++) {
        distance[i] = INFINITY;
        visited[i] = false;
    }

    distance[startNode] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int currentNode = getClosestNode();
        visited[currentNode] = true;

        for (int i = 0; i < numNodes; i++) {
            if (!visited[i] && graph[currentNode][i] && distance[currentNode] != INFINITY
                && distance[currentNode] + graph[currentNode][i] < distance[i]) {
                distance[i] = distance[currentNode] + graph[currentNode][i];
            }
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
while(1)
{


    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    dijkstra(startNode);

    printf("Shortest distances from node %d:\n", startNode);
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: Distance = %d\n", i, distance[i]);
    }
}

    return 0;
}
