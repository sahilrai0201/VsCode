#include<bits/stdc++.h>
using namespace std;

// Function to maintain MIN HEAP property (0-based indexing)
void heapify(int arr[], int n, int i){
    int smallest = i;          // Assume current node is smallest
    int left = 2*i + 1;        // Left child index (0-based)
    int right = 2*i + 2;       // Right child index (0-based)

    // If left child exists and is smaller than current node
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    // If right child exists and is smaller than current smallest
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    // If smallest is not the current node
    if(smallest != i){
        swap(arr[i], arr[smallest]);  // Swap with smaller child

        // Recursively heapify the affected subtree
        heapify(arr, n, smallest);
    }
}

int main(){

    // Array using 0-based indexing
    int arr[5] = {54, 53, 55, 52, 50};
    int n = 5;

    // Build MIN heap (start from last non-leaf node)
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing the Min Heap:" << endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}