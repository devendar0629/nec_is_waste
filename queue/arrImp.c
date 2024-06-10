#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the queue structure
struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

// Initialize an empty queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}

// Check if the queue is full
bool isFull(struct Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

// Add an element to the rear of the queue (enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Initialize front when adding the first element
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Remove an element from the front of the queue (dequeue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        // Reset queue when removing the last element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Get the front element without removing it
int top(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->data[q->front];
}

int main() {
    struct Queue myQueue;
    initQueue(&myQueue);

    // Example usage
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front element: %d\n", top(&myQueue));

    printf("Dequeued element: %d\n", dequeue(&myQueue));
    printf("Dequeued element: %d\n", dequeue(&myQueue));

    printf("Front element: %d\n", top(&myQueue));

    return 0;
}
