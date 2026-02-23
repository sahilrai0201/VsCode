#include <iostream>
using namespace std;

int countDistinctWayToClimbStair(int n){

    //base case
    if(n < 0) return 0;      //there's no such stair
    if(n == 0) return 1;     //number of ways to reach 0th stair from 0th is 1

    //recursive relation
    //you can reach a particular stair either by taking a single step or double step
    return countDistinctWayToClimbStair(n-1) + countDistinctWayToClimbStair(n-2);        

}

int main() {
    int n;
    cout << "Enter the number of stairs : ";
    cin >> n;

    int ans = countDistinctWayToClimbStair(n);
    cout << ans << endl;

    return 0;
}
