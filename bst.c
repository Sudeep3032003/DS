#include <stdio.h>
#include <stdlib.h>

struct node {
  int data ;
  struct node *right_child;
  struct node *left_child;
};

struct node* new_node(int x){
  struct node *temp;
  temp = malloc(sizeof(struct node));
  temp->data = x;
  temp->left_child = NULL;
  temp->right_child = NULL;

  return temp;
}

struct node* search(struct node * root, int x)
{
  if (root == NULL)
  {
      printf("Value %d not found\n" , x);
      return NULL;
  }
  else
    if(root->data == x)
  {
      printf("Value %d found \n" , x);
      return root;
  }
  else if (x < root->data)
    return search(root->left_child, x);
  else
    return search(root->right_child, x);
}

struct node* insert(struct node * root, int x){
  if (root == NULL)
    return new_node(x);
  else if (x > root->data)
    root->right_child = insert(root->right_child, x);
  else
    root -> left_child = insert(root->left_child, x);
  return root;
}
struct node* find_minimum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root->left_child != NULL)
    return find_minimum(root->left_child);
  return root;
}
struct node* find_maximum(struct node * root) {
  if (root == NULL)
    return NULL;
  else if (root->right_child != NULL)
    return find_maximum(root->right_child);
  return root;
}
int main() {
  struct node *root;
  root = new_node(20);
  insert(root, 5);
  insert(root, 1);
  insert(root, 15);
  insert(root, 9);
  insert(root, 7);
  insert(root, 12);
  insert(root, 30);
  insert(root, 25);
  insert(root, 40);
  insert(root, 45);
  insert(root, 42);
  search(root,30);
  search(root,100);

struct node* max_node = find_maximum(root);
if (max_node != NULL) {
    int maximum_value = max_node->data;
    printf("The maximum value in the tree is: %d\n", maximum_value);
} else {
    printf("The tree is empty, so there is no maximum value.\n");
}
struct node* min_node = find_minimum(root);
if (min_node != NULL) {
    int minimum_value = min_node->data;
    printf("The minimum value in the tree is: %d\n", minimum_value);
} else {
    printf("The tree is empty, so there is no minimum value.\n");
}

  return 0;
}
