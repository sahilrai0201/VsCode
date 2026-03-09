//TC is O(n) because of optimisation flag : 
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){   //already sorted
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "Sorted array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
} 



//BUBBLE SORT THROUGH RECURSION : 
// #include<bits/stdc++.h>
// using namespace std;

// void bubbleSort(int arr[], int n){
//     //base case
//     if(n == 0 || n == 1) return;

//     //solve first case and rest will be done through recursion
//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i] > arr[i + 1]){
//             swap (arr[i], arr[i + 1]);
//         }
//     }
//     //recursive call
//     bubbleSort (arr, n-1);
// }

// int main() {
//     int arr[6] = {2,6,4,5,11,7};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     bubbleSort(arr, n);

//     cout << "sorted array : ";
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// } 
