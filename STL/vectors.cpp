// VECTORS EXPLANATION

#include<bits/stdc++.h>
using namespace std;

void explainVector(){

    // Creating an empty vector
    vector<int> v;

    // Adding elements
    v.push_back(1);       // Adds 1 at the end
    v.emplace_back(2);    // Constructs element in-place (slightly faster)
    v.push_back(3);
    v.push_back(4);

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    // Vector with 5 elements, all initialized to 100
    vector<int> vt(5, 100);   // {100,100,100,100,100}

    // Vector with 5 elements initialized to 0
    vector<int> vtr(5);       // {0,0,0,0,0}

    // Copying one vector to another
    vector<int> v1(5, 20);
    vector<int> v2(v1);       // copy constructor

    // Iterator
    vector<int>::iterator it = v.begin();

    it++;   // Move to next element
    cout << *(it) << endl;   // prints 2

    it = it + 1;            // Move forward
    cout << *(it) << endl;  // prints 3

    // v.end() points to memory AFTER last element
    it = v.end();  // NEVER dereference this

    // Accessing elements
    cout << v[0] << " & " << v.at(0) << endl;  
    // v.at() is safer (throws exception if out of range)

    cout << v.back() << endl;  // last element

    // Normal iterator loop
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    // Using auto keyword
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    cout << endl;

    // Range-based for loop (Best & cleanest)
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;

    // Erase single element (removes element at index 1)
    v.erase(v.begin() + 1);

    // Erase range [start, end)
    // Removes elements at index 1 only
    v.erase(v.begin() + 1, v.begin() + 2);

    // -------------------------
    // INSERT FUNCTION
    // -------------------------

    vector<int> v3(2, 100);   // {100,100}

    v3.insert(v3.begin(), 300);    
    // {300,100,100}

    v3.insert(v3.begin() + 1, 2, 10);  
    // Inserts two 10s
    // {300,10,10,100,100}

    vector<int> copy(2, 50);  
    // {50,50}

    v3.insert(v3.begin(), copy.begin(), copy.end());
    // {50,50,300,10,10,100,100}

    cout << v3.size() << endl;  // prints size

    // Remove last element
    v3.pop_back();

    // Swap contents of v1 and v2
    v1.swap(v2);

    // Clear all elements
    v3.clear();

    // Check if vector is empty (returns 1 for true, 0 for false)
    cout << v3.empty() << endl;
}

int main(){
    explainVector();
    return 0;
}