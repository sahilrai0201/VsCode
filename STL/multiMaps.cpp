// MULTIMAP EXPLANATION
#include<bits/stdc++.h>
using namespace std;

void explainMultiMap(){

    multimap<int, string> mm;

    // Insert elements (duplicate keys allowed)
    mm.insert({1, "Sahil"});
    mm.insert({2, "Rai"});
    mm.insert({1, "C++"});
    mm.insert({2, "Engineering"});
    mm.insert({3, "STL"});

    cout << "Multimap elements:\n";
    for(auto it : mm){
        cout << it.first << " -> " << it.second << endl;
        // Keys are stored in SORTED order
        // Duplicate keys are allowed
    }

    // Size (counts all elements including duplicates)
    cout << "Size: " << mm.size() << endl;

    // Find (returns iterator to first occurrence)
    auto it = mm.find(1);
    if(it != mm.end()){
        cout << "First value of key 1: " << it->second << endl;
    }

    // Count (number of elements with that key)
    cout << "Count of key 1: " << mm.count(1) << endl;

    // Erase all elements with key 2
    mm.erase(2);

    cout << "After erase key 2:\n";
    for(auto it : mm){
        cout << it.first << " -> " << it.second << endl;
    }
}

int main(){
    explainMultiMap();
    return 0;
}