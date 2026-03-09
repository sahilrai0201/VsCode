#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        for( ; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    int n; 
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;

    insertionSort(arr, n); 

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



//RECURSIVE INSERTION SORT
// #include <bits/stdc++.h>
// using namespace std;

// void insertionSort(int arr[], int n){ 
//     // Base case
//     if(n <= 1){
//         return;
//     }

//     // Sort first n-1 elements
//     insertionSort(arr, n-1);

//     // Insert last element at correct position
//     int last = arr[n-1];
//     int j = n-2;

//     while(j >= 0 && arr[j] > last){
//         arr[j+1] = arr[j];
//         j--;
//     }

//     arr[j+1] = last;
// }

// int main(){
//     int arr[] = {5, 3, 4, 1, 2};
//     int n = 5;

//     insertionSort(arr, n);

//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
// }