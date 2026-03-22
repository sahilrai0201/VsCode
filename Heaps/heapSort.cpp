#include<bits/stdc++.h>
using namespace std;

// Function to maintain max heap property
void heapify(int arr[], int n, int i){
    int largest = i;        // Assume current node is largest
    int left = 2*i;         // Left child index
    int right = 2*i + 1;    // Right child index

    // Check if left child exists and is greater than current largest
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    // Check if right child exists and is greater than current largest
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // If largest is not the root node
    if(largest != i){
        swap(arr[largest], arr[i]);  // Swap with the largest child

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        //step1 : swapping
        swap(arr[size], arr[1]);
        size--;

        //step2: 
        heapify(arr, size, 1);
    }
}

int main(){

    // Array representation of heap (1-based indexing, arr[0] unused)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;  // Number of elements in heap

    // Build max heap by calling heapify from last non-leaf node to root
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the array" << endl;
    // Print the heap (1-based indexing)
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //heapSort
    heapSort(arr, n);

    cout << "Printing the sorted array" << endl;
    // Print the heap (1-based indexing)
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}