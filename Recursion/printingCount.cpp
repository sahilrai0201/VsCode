//PRINTING FROM 1 TO N :
// #include<bits/stdc++.h>
// using namespace std;

// void print(int start, int end){
//     if(start > end) return;
//     cout << start << endl;
//     print(start + 1, end);
// }

// int main(){
//     int n1;
//     cout << "Enter the starting number : " << endl;
//     cin >> n1;
//     int n2;
//     cout << "Enter the ending number : " << endl;
//     cin >> n2;

//     cout << "Counting form 1 to N is : " << endl;
//     print(n1, n2);
//     return 0;
// }







//PRINTING FROM N TO 1 :
#include<bits/stdc++.h>
using namespace std;

void print(int start, int end){
    if(start > end) return;
    cout << end << endl;
    print(start, end-1);
}

int main(){
    int n1;
    cout << "Enter the starting number : " << endl;
    cin >> n1;
    int n2;
    cout << "Enter the ending number : " << endl;
    cin >> n2;

    cout << "Counting form 1 to N is : " << endl;
    print(n1, n2);
    return 0;
}