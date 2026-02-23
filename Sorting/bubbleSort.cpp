#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    //base case
    if(n == 0 || n == 1) {
        return;
    }

    //solve first case and rest will be done through recursion
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]){
            swap (arr[i], arr[i + 1]);
        }
    }
    //recursive call
    bubbleSort (arr, n-1);
}

int main() {

    int arr[6] = {2,6,4,5,11,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "sorted array : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} 
