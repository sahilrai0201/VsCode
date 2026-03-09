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