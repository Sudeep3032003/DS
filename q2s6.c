#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize a stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return -1; // Error value
    } else {
        return stack->arr[stack->top--];
    }
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Stack *s1, struct Stack *s2, int value) {
    // Move all elements from s1 to s2
    while (!isEmpty(s1)) {
        push(s2, pop(s1));
    }

    // Push the new element onto s1
    push(s1, value);

    // Move all elements back from s2 to s1
    while (!isEmpty(s2)) {
        push(s1, pop(s2));
    }

    printf("%d enqueued to the queue\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Stack *s1) {
    if (isEmpty(s1)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue\n");
        return -1; // Error value
    } else {
        int dequeuedValue = pop(s1);
        printf("%d dequeued from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int main() {
    struct Stack stack1, stack2;
    initialize(&stack1);
    initialize(&stack2);

    enqueue(&stack1, &stack2, 10);
    enqueue(&stack1, &stack2, 20);
    enqueue(&stack1, &stack2, 30);

    dequeue(&stack1);
    dequeue(&stack1);

    enqueue(&stack1, &stack2, 40);

    return 0;
}
