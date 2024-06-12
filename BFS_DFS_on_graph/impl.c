#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

// ---------------- Queue Implementation START -------------------

struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

typedef struct Node Node;
typedef struct Queue Queue;

Queue* getQueue() {
    Queue* q = (Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int isEmpty(Queue* q) {
    return (q->size == 0);
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue* q) {
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;

    if (isEmpty(q)) {
        q->rear = NULL;
    }
    return value;
}

int top(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// ---------------- Queue Implementation END -------------------


struct Graph {
    int adjMat[MAX_VERTICES+1][MAX_VERTICES+1]; // Adjacency Matrix
    int vertexCount;
};

typedef struct Graph Graph;

void addEdge(Graph* gp,int x,int y) {
    gp->adjMat[x][y] = 1;
    gp->adjMat[y][x] = 1; // For undirected graph
}

void initGraph(Graph* gp,int vertexCount) {
    if(vertexCount > MAX_VERTICES) {
        printf("Vertex count is too large !\n");
        return;
    }

    gp->vertexCount = vertexCount;
    for(int i = 0;i <= vertexCount;i++) {
        for(int j = 0;j <= vertexCount;j++) {
            gp->adjMat[i][j] = 0;
        }
    }
}

void printBFS(Graph* gp,int startVertex) {
    Queue* q = getQueue();
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ",currentVertex);

        for (int i = 0; i < gp->vertexCount; i++) {
            // has an edge and it is unvisited
            if (gp->adjMat[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    printf("\n");
}

void printDFS(Graph* gp,int startVertex,int* visited) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < gp->vertexCount; i++) {
        // has an edge and it is unvisited
        if (gp->adjMat[startVertex][i] && !visited[i]) {
            printDFS(gp, i, visited);
        }
    }
}

int main() {
    Graph* g = (Graph*) malloc(sizeof(Graph));

    initGraph(g,10);

    addEdge(g,0,1);
    addEdge(g,0,2);
    addEdge(g,0,3);

    addEdge(g,1,2);
    addEdge(g,1,3);

    addEdge(g,3,5);
    addEdge(g,3,4);

    printf("BFS: ");
    printBFS(g,0);

    int visited[10] = {0};
    printf("DFS: ");
    printDFS(g,0,visited);

    return 0;
}