#include <stdio.h>
#include <stdlib.h>

// Define the queue node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Initialize an empty queue
struct Queue* initQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

// Check if the queue is full (not applicable for linked list implementation)
int isFull(struct Queue* q) {
    return (q->size >= 100);
}

// Add an element to the rear of the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Remove an element from the front of the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (isEmpty(q)) {
        q->rear = NULL; // Reset rear when removing the last element
    }
    return value;
}

// Get the front element without removing it
int top(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Free memory and destroy the queue
void destroyQueue(struct Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    struct Queue* myQueue = initQueue();

    // Example usage
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Front element: %d\n", top(myQueue));

    printf("Dequeued element: %d\n", dequeue(myQueue));
    printf("Dequeued element: %d\n", dequeue(myQueue));

    printf("Front element: %d\n", top(myQueue));

    destroyQueue(myQueue); // Clean up memory

    return 0;
}
