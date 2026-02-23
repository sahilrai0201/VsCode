#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for(int i = start + 1; i <= end; i++) {
        if(arr[i] <= pivot)  {
            count++;
        }
    }

    int pivotIndex = start + count;     //right place for pivot element in the array
    swap(arr[pivotIndex], arr[start]);

    //now consider the right & left part of pivotIndex element
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {

    //base case
    if(start >= end) {
        return;
    }

    //partiton
    int p = partition(arr, start, end);

    //sorting left part
    quickSort(arr, start, p-1);

    //sorting right part
    quickSort(arr, p+1, end);
}

int main() {

    int arr[10] = {2, 6, 5, 7, 11, 9, 3, 8 , 4, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    cout << "Sorted array : ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}
