#include<bits/stdc++.h>
using namespace std;

// Creating a Max Heap class
class heap{
    public:
    int arr[100];   // Array to store heap elements (1-based indexing)
    int size;       // Current size of heap

    // Constructor to initialize heap
    heap(){
        arr[0] = -1;  // Dummy value at index 0 (not used)
        size = 0;     // Initially heap is empty
    }

    // Function to insert a value into heap
    void insert(int val){
        size = size + 1;   // Increase heap size
        int index = size;  // Insert element at last position
        arr[index] = val;

        // Move the element upward to maintain Max Heap property (Heapify Up)
        while(index > 1){
            int parent = index / 2;   // Find parent index

            // If parent is smaller than current node, swap them
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;  // Move index to parent
            }
            else{
                return;  // Heap property is satisfied
            }
        }
    }

    // Function to print heap elements (level order)
    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to delete root element (maximum element)
    void deletefromHeap(){
        // If heap is empty
        if(size == 0){
            cout << "Nothing to delete!" << endl;
            return;
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size];
        size--;

        // Step 2: Move root element to its correct position (Heapify Down)
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;       // Left child index
            int rightIndex = 2*i + 1;  // Right child index

            // If left child exists and is greater than current node
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;  // Move to left child
            }
            // If right child exists and is greater than current node
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex; // Move to right child
            }
            else{
                return;  // Heap property satisfied
            }
        }
    }

};

int main(){
    heap h;

    // Inserting elements into heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // Printing heap (level order traversal)
    h.print();

    // Deleting root element (maximum element)
    h.deletefromHeap();

    // Printing heap after deletion
    h.print();

    return 0;
}