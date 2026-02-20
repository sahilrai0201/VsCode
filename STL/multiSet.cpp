// MULTISET EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainMultiset(){
    multiset<int> ms;

    // Insert elements (duplicates allowed)
    ms.insert(5);
    ms.insert(1);
    ms.insert(3);
    ms.insert(1);   // duplicate allowed
    ms.insert(5);

    cout << "Multiset elements: ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    // Size includes duplicates
    cout << "Size: " << ms.size() << endl;

    // Count occurrences of a value
    cout << "Count of 1 : " << ms.count(1) << endl;

    // Find element (returns iterator to first occurrence)
    auto it = ms.find(5);
    if(it != ms.end())
        cout << "Found 5\n";

    // Erase one occurrence of 5
    ms.erase(ms.find(5));

    cout << "After erasing one 5 : ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;

    // Erase all occurrences of 1
    ms.erase(1);

    cout << "After erasing all 1s: ";
    for(auto it : ms){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    explainMultiset();
    return 0;
}