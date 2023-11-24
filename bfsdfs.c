#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define a structure to represent a node
struct Node {
int data;
struct Node* next;
};
// Define a structure to represent a graph
struct Graph {
int V;
struct Node** adjList;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Function to create a graph with 'V' vertices
struct Graph* createGraph(int V) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
graph->V = V;
graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
for (int i = 0; i < V; i++)
graph->adjList[i] = NULL;
return graph;
}
// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
struct Node* newNode = createNode(dest);
newNode->next = graph->adjList[src];
graph->adjList[src] = newNode;
}
// Function to perform Depth-First Search using a stack
void DFS(struct Graph* graph, int startVertex) {
bool* visited = (bool*)malloc(graph->V * sizeof(bool));
for (int i = 0; i < graph->V; i++)
visited[i] = false;
struct Node* stack[graph->V];
int top = -1;
stack[++top] = createNode(startVertex);
while (top >= 0) {
struct Node* current = stack[top--];
int vertex = current->data;
if (!visited[vertex]) {
printf("%d ", vertex);
visited[vertex] = true;
}
struct Node* temp = graph->adjList[vertex];
while (temp != NULL) {
int adjVertex = temp->data;
if (!visited[adjVertex])
stack[++top] = createNode(adjVertex);
temp = temp->next;
}
free(current);
}
free(visited);
}
// Function to perform Breadth-First Search using a queue
void BFS(struct Graph* graph, int startVertex) {
bool* visited = (bool*)malloc(graph->V * sizeof(bool));
for (int i = 0; i < graph->V; i++)
visited[i] = false;
struct Node* queue[graph->V];
int front = 0, rear = 0;
queue[rear++] = createNode(startVertex);
visited[startVertex] = true;
while (front < rear) {
struct Node* current = queue[front++];
int vertex = current->data;
printf("%d ", vertex);
struct Node* temp = graph->adjList[vertex];
while (temp != NULL) {
int adjVertex = temp->data;
if (!visited[adjVertex]) {
queue[rear++] = createNode(adjVertex);
visited[adjVertex] = true;
}
temp = temp->next;
}
free(current);
}
free(visited);
}
// Driver code
int main() {
int V = 5;
struct Graph* graph = createGraph(V);
addEdge(graph, 0, 1);
addEdge(graph, 0, 2);
addEdge(graph, 0, 3);
addEdge(graph, 1, 3);
addEdge(graph, 1, 4);
addEdge(graph, 2, 4);
printf("Depth-First Search starting from vertex 0: ");
DFS(graph, 0);
printf("\n");
printf("Breadth-First Search starting from vertex 0: ");
BFS(graph, 0);
printf("\n");
return 0;
}
