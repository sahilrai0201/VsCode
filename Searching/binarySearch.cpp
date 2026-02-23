//this is my first change

#include <iostream>               
using namespace std;

bool binarySearch (int arr[], int start, int end, int key) {
    
    //base case
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        return true;
    }

    //recursive case
    if (arr[mid] < key) {
        return binarySearch (arr, mid + 1, end, key);
    } 
    else { 
        return binarySearch (arr, start, mid - 1, key);
    }

}

int main() {

    int arr[6] = {2, 4, 6, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    //present - 1 & not present - 0
    cout << " Present or not : " << binarySearch (arr, 0, n-1, key) << endl;     

    return 0;
}
