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
        int index = size;  // Insert at last position
        arr[index] = val;

        // Move the element up to maintain Max Heap property
        while(index > 1){
            int parent = index / 2;

            // If parent is smaller, swap
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;  // Move to parent index
            }
            else{
                return;  // Heap property satisfied
            }
        }
    }

    // Function to print heap elements
    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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

    // Printing heap (level order)
    h.print();

    return 0;
}