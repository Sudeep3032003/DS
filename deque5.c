#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int front, rear;
    int arr[MAX_SIZE];
};

// Function to initialize a deque
void initialize(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque) {
    return (deque->front == -1 && deque->rear == -1);
}

// Function to check if the deque is full
int isFull(struct Deque *deque) {
    return (deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque Overflow! Cannot insert at the front: %d\n", value);
    } else {
        if (isEmpty(deque)) {
            // If the deque is empty, set both front and rear to 0
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->front == 0) {
            // If the front is at the beginning, move it to the end in a circular manner
            deque->front = MAX_SIZE - 1;
        } else {
            // Move front to the previous position
            deque->front--;
        }

        // Insert at the front
        deque->arr[deque->front] = value;
        printf("%d inserted at the front of the deque\n", value);
    }
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(deque)) {
        printf("Deque Overflow! Cannot insert at the rear: %d\n", value);
    } else {
        if (isEmpty(deque)) {
            // If the deque is empty, set both front and rear to 0
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->rear == MAX_SIZE - 1) {
            // If the rear is at the end, move it to the beginning in a circular manner
            deque->rear = 0;
        } else {
            // Move rear to the next position
            deque->rear++;
        }

        // Insert at the rear
        deque->arr[deque->rear] = value;
        printf("%d inserted at the rear of the deque\n", value);
    }
}

// Function to delete an element from the front of the deque
int deleteFront(struct Deque *deque) {
    int deletedValue;

    if (isEmpty(deque)) {
        printf("Deque Underflow! Cannot delete from an empty deque\n");
        return -1; // Error value
    } else if (deque->front == deque->rear) {
        // If there's only one element in the deque
        deletedValue = deque->arr[deque->front];
        deque->front = -1;
        deque->rear = -1;
    } else {
        // Delete from the front
        deletedValue = deque->arr[deque->front];
        // Move front to the next position
        deque->front = (deque->front + 1) % MAX_SIZE;
    }

    printf("%d deleted from the front of the deque\n", deletedValue);
    return deletedValue;
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque *deque) {
    int deletedValue;

    if (isEmpty(deque)) {
        printf("Deque Underflow! Cannot delete from an empty deque\n");
        return -1; // Error value
    } else if (deque->front == deque->rear) {
        // If there's only one element in the deque
        deletedValue = deque->arr[deque->rear];
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        // If the rear is at the beginning, move it to the end in a circular manner
        deletedValue = deque->arr[deque->rear];
        deque->rear = MAX_SIZE - 1;
    } else {
        // Delete from the rear
        deletedValue = deque->arr[deque->rear];
        // Move rear to the previous position
        deque->rear--;
    }

    printf("%d deleted from the rear of the deque\n", deletedValue);
    return deletedValue;
}

int main() {
    struct Deque deque;
    initialize(&deque);

    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);
    insertFront(&deque, 15);

    deleteFront(&deque);
    deleteRear(&deque);

    return 0;
}
