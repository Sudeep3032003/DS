#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    // Traverse to the end of the list
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end
    current->next = newNode;
    return head;
}

// Function to delete a node with the given data from the linked list
struct Node *deleteNode(struct Node *head, int data) {
    if (head == NULL) {
        printf("List is empty, cannot delete\n");
        return NULL;
    }

    // If the node to be deleted is the head
    if (head->data == data) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Node with data %d deleted from the list\n", data);
        return head;
    }

    // Traverse the list to find the node to be deleted
    struct Node *current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    // If the node with the given data is found, delete it
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("Node with data %d deleted from the list\n", data);
    } else {
        printf("Node with data %d not found in the list\n", data);
    }

    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Display the linked list
    displayList(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    // Display the linked list
    displayList(head);

    // Delete a node
    head = deleteNode(head, 20);

    // Display the linked list after deletion
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
