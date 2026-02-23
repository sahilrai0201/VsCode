#include <iostream>
using namespace std;

bool linearSearch (int arr[], int n, int key) {
    
    //base cases
    if (n == 0) {
        return false;
    }
    if (arr[0] == key) {
        return true;
    }
    else {

        //first element is already checked thus arr=arr+1 & n=n-1
        int remainingPart = linearSearch (arr+1, n-1, key);       
        return remainingPart;
    }

}

int main() {

    int arr[6] = {2, 4, 6, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    if (linearSearch (arr, n, key)) cout << "Key is found in the given array!" << endl;
    else cout << "Not found!" << endl;

    return 0;
}
