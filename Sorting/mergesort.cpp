#include <iostream>
using namespace std;

void merge(int arr[], int start, int end) {
    int mid = (start + end)/2;

    int len1 = mid - start + 1;     //length of first array
    int len2 = end - mid;           //length of second array

    int *first = new int[len1];    //creating two new arrays
    int *second = new int[len2];

    //copying values
    int mainArrayIndex = start;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted arrays 
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;
    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    //delete those dynamically allocated memories otherwise you will face memory leakage
    delete []first;
    delete []second;
}

void mergeSort(int arr[], int start, int end) {

    //base case
    if(start >= end) return;

    int mid = (start + end)/2;

    //sort the left part
    mergeSort(arr, start, mid);

    //sort the right part
    mergeSort(arr, mid+1, end);

    //merge both parts
    merge(arr, start, end);

}

int main() {

    int arr[6] = {2,6,4,5,11,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    cout << "sorted array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} 
