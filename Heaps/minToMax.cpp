#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int i){
    int n = arr.size();

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < n && arr[l] > arr[i]){
        largest = l;
    }

    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void convertMaxHeap(vector<int> &arr){
    int n = arr.size();

    for(int i = (n-2)/2; i >= 0; --i){
        maxHeapify(arr, i);
    }
}

int main(){
    int n;
    cout << "Enter the size of array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    convertMaxHeap(arr);

    cout << "Array after converted into max heap is : " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}



// OUTPUT :
// -------------------------------->
// Enter the size of array : 
// 10
// Enter the array : 
// 3 5 9 6 8 20 10 12 18 9 
// Array after converted into max heap is : 
// 20 18 10 12 9 9 3 5 6 8 