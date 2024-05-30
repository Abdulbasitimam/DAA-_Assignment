#include <stdio.h>
#include <stdlib.h>

// structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct AdjList* createAdjList(int V) {
    struct AdjList* adjList = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        adjList[i].head = NULL;
    }
    return adjList;
}

void addEdge(struct AdjList* adjList, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = adjList[dest].head;
    adjList[dest].head = newNode;
}

void printAdjList(struct AdjList* adjList, int V) {
    for (int i = 0; i < V; i++) {
        struct AdjListNode* temp = adjList[i].head;
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 4;  // number of vertices
    struct AdjList* adjList = createAdjList(V);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);

    printAdjList(adjList, V);

    return 0;
}