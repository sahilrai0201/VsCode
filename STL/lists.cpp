// LISTS EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainList(){

    // list is implemented as a doubly linked list
    list<int> ls;

    // Insert element at the back
    ls.push_back(2);        // {2}

    // emplace_back constructs element in-place
    ls.emplace_back(4);     // {2,4}

    // Insert element at the front
    ls.push_front(5);       // {5,2,4}

    // Insert at front using emplace
    ls.emplace_front(1);    // {1,5,2,4}

    // Printing list using range-based loop
    for(auto it : ls){
        cout << it << " ";
    }
    cout << endl;

    // Removing elements
    ls.pop_back();          // removes 4 → {1,5,2}
    ls.pop_front();         // removes 1 → {5,2}

    // Printing again
    for(auto it : ls){
        cout << it << " ";
    }
    cout << endl;

    // Other useful functions
    cout << ls.size() << endl;    // number of elements
    cout << ls.front() << endl;   // first element
    cout << ls.back() << endl;    // last element
}

int main(){
    explainList();
    return 0;
}