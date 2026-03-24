#include<bits/stdc++.h>
using namespace std;

int main(){

    // creation of unordered_map
    // key -> string, value -> int
    unordered_map<string, int> mp;

    // ---------------- INSERTION ----------------

    // method 1: using make_pair
    pair<string, int> p = make_pair("sahil", 3);
    mp.insert(p);

    // method 2: direct pair initialization
    pair<string, int> p2("rai", 2);
    mp.insert(p2);

    // method 3: using [] operator
    mp["mera"] = 1;

    // if key already exists, value gets UPDATED
    mp["mera"] = 2;

    // ---------------- SEARCHING ----------------

    // method 1: using [] operator
    // returns value if key exists
    cout << mp["mera"] << endl;

    // method 2: using at()
    // also returns value if key exists
    cout << mp.at("sahil") << endl;

    // ---------------- IMPORTANT DIFFERENCE ----------------

    // if key does NOT exist:
    // [] operator inserts key with default value (0 for int)
    cout << mp["unknownKey"] << endl;   // prints 0 and creates key

    // at() throws runtime error if key not found
    cout << mp.at("unknownKey") << endl; // throws out_of_range exception


    //size
    // size() returns total number of key-value pairs in the map
    cout << mp.size() << endl;       //prints 4

    //to check presence
    // count(key) checks whether key exists or not
    // returns 1 if present, 0 if absent
    cout << mp.count("sahil") << endl;        //prints 1 : present
    cout << mp.count("bro") << endl;          //prints 0 : absent

    //erase
    // erase(key) removes the key-value pair from the map
    mp.erase("rai");     

    // after deletion, size decreases
    cout << mp.size() << endl;  //prints 3

    //accessing -> method 1 ->
    // range-based loop: each element is a pair (key, value)
    for(auto i : mp){
        cout << i.first << " " << i.second <<endl;
    }

    //accessing -> method 2 ->
    // using iterator to traverse the map
    unordered_map<string, int> :: iterator it = mp.begin();

    // loop until iterator reaches end()
    while(it != mp.end()){
        // it->first gives key, it->second gives value
        cout << it->first << " " << it->second << endl;
        it++;   // move iterator to next element
    }

    return 0;
}