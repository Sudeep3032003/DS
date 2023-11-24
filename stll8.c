#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node *next;
} Node;
 
Node *head = NULL;
 
Node *get_node(int val) 
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (new == NULL) 
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    new->data = val;
    new->next = NULL;
    return new;
}
 
void push() {
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
 
    Node *temp = get_node(val);
    if (temp == NULL) 
    {
        printf("Not able to push the element\n");
    } 
    else 
    {
        if (head == NULL) 
        {
            head = temp;
        } 
    else 
        {
            temp->next = head;
            head = temp;
        }
        printf("Item pushed: %d\n", val);
    }
}
 
void pop() 
{
    int item;
    if (head == NULL) 
    {
        printf("Underflow Condition\n");
    } 
    else 
    {
        Node *temp = head;
        item = temp->data;
        head = head->next;
        free(temp);
        printf("Item popped: %d\n", item);
    }
}
 
void display() {
    Node *temp = head;
 
    if (temp == NULL) {
        printf("Empty Linked List\n");
    } 
    else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
 
void main()
{
    int ch;
 
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
 
        printf("Enter the choice: ");
        scanf("%d", &ch);
 
        switch (ch)
        {
            case 1:
                push();
                break;
 
            case 2:
                pop();
                break;
 
            case 3:
                display();
                break;
 
            case 4:
                exit(0);
 
            default:
                printf("Invalid choice\n");
        }
    }
}
