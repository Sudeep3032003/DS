#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize a queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int value) {
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
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue) {
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

    return dequeuedValue;
}

// Function to push an element onto the stack
void push(struct Queue *q1, struct Queue *q2, int value) {
    // Enqueue the element into the non-empty queue
    if (!isEmpty(q1)) {
        enqueue(q1, value);
    } else {
        enqueue(q2, value);
    }

    printf("%d pushed to the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Queue *q1, struct Queue *q2) {
    int poppedValue;

    if (isEmpty(q1) && isEmpty(q2)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Error value
    } else {
        // Dequeue all elements from the non-empty queue to the empty queue, except the last one
        if (!isEmpty(q1)) {
            while (q1->front != q1->rear) {
                enqueue(q2, dequeue(q1));
            }
            poppedValue = dequeue(q1);
        } else {
            while (q2->front != q2->rear) {
                enqueue(q1, dequeue(q2));
            }
            poppedValue = dequeue(q2);
        }

        printf("%d popped from the stack\n", poppedValue);
        return poppedValue;
    }
}

int main() {
    struct Queue queue1, queue2;
    initialize(&queue1);
    initialize(&queue2);

    push(&queue1, &queue2, 10);
    push(&queue1, &queue2, 20);
    push(&queue1, &queue2, 30);

    pop(&queue1, &queue2);
    pop(&queue1, &queue2);

    push(&queue1, &queue2, 40);

    return 0;
}
