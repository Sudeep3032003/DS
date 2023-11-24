#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize a circular queue
void initialize(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (isEmpty(queue)) {
            // If the queue is empty, set both front and rear to 0
            queue->front = 0;
            queue->rear = 0;
        } else {
            // Move rear to the next position in a circular manner
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }

        // Enqueue the element
        queue->arr[queue->rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct CircularQueue *queue) {
    int dequeuedValue;

    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1; // Error value
    } else if (queue->front == queue->rear) {
        // If there's only one element in the queue
        dequeuedValue = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Dequeue the element
        dequeuedValue = queue->arr[queue->front];
        // Move front to the next position in a circular manner
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue\n", dequeuedValue);
    return dequeuedValue;
}

int main() {
    struct CircularQueue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    dequeue(&queue);
    dequeue(&queue);

    enqueue(&queue, 50);
    enqueue(&queue, 60);

    return 0;
}
