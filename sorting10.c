#include <stdio.h>
#include <stdlib.h>
// Function to swap two elements in an array
void swap(int arr[], int a, int b) {
int temp = arr[a];
arr[a] = arr[b];
arr[b] = temp;
}
// Function to display the elements of an array
void displayArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Function for Quick Sort algorithm
void quickSort(int arr[], int low, int high)
{
int n;
if (low < high) {
int pivot = arr[low];
int i = low;
int j = high;
while (i <= j) {
while (arr[i] < pivot) {
i++;
}
while (arr[j] > pivot) {
j--;
}
if (i <= j) {
swap(arr, i, j);
i++;
j--;
}
}
printf("Pivot selected: %d\n", pivot);
displayArray(arr, high + 1);
if (low < j) {
quickSort(arr, low, j);
}
if (i < high) {
quickSort(arr, i, high);
}
}
}
// Function for Insertion Sort algorithm
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
printf("Step %d: ", i);
displayArray(arr, n);
}
}
// Function to maintain the max-heap property
void heapify(int arr[], int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest]) {
largest = left;
}
if (right < n && arr[right] > arr[largest]) {
largest = right;
}
if (largest != i) {
swap(arr, i, largest);
heapify(arr, n, largest);
}
}
// Function for Heap Sort algorithm
void heapSort(int arr[], int n) {
for (int i = n / 2 - 1; i >= 0; i--) {
heapify(arr, n, i);
}
for (int i = n - 1; i >= 0; i--) {
swap(arr, 0, i);
heapify(arr, i, 0);
printf("Step %d: ", n - i);
displayArray(arr, n);
}
}
int main() {
int originalArr[] = {99,86,44,35,11};
int n = sizeof(originalArr) / sizeof(originalArr[0]);
int sortedArr[n];
int copyArr[n];
for (int i = 0; i < n; i++) {
sortedArr[i] = originalArr[i];
copyArr[i] = originalArr[i];
}
printf("Original Numbers: ");
displayArray(originalArr, n);
printf("\n\n");
while (1) {
int choice;
printf("Menu:\n");
printf("1. Quick Sort\n");
printf("2. Insertion Sort\n");
printf("3. Heap Sort\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
// Sort the sortedArr using Quick Sort and display intermediate steps
quickSort(sortedArr, 0, n - 1);
printf("Sorted Numbers using Quick Sort:\n");
displayArray(sortedArr,n);
printf("\n");
break;
case 2:
// Reset sortedArr to its original state (copyArr) and sort using Insertion Sort while displaying steps
for (int i = 0; i < n; i++) {
sortedArr[i] = copyArr[i];
}
printf("Sorted Numbers using Insertion Sort:\n");
insertionSort(sortedArr, n);
printf("\n");
break;
case 3:
// Reset sortedArr to its original state (copyArr) and sort using Heap Sort while displaying steps
for (int i = 0; i < n; i++) {
sortedArr[i] = copyArr[i];
}
printf("Sorted Numbers using Heap Sort:\n");
heapSort(sortedArr, n);
printf("\n");
break;
case 4:
exit(0);
default:
printf("Invalid choice. Please enter 1, 2, 3, or 4.\n\n");
}
}
return 0;
}
