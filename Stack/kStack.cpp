#include<iostream>
using namespace std;

class kStacks {
public:
    int n;          // size of array
    int k;          // number of stacks
    int *arr;       // main array
    int *top;       // top elements of each stack
    int *next;      // next free / next element
    int freeSpot;   // beginning of free list

public:
    // Constructor
    kStacks(int n, int k){
        this->n = n;
        this->k = k;

        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // initialize all stacks as empty
        for(int i = 0; i < k; i++){
            top[i] = -1;
        }

        // initialize free list
        for(int i = 0; i < n-1; i++){
            next[i] = i + 1;
        }
        next[n-1] = -1;

        freeSpot = 0;
    }

    // PUSH
    void push(int data, int sn){

        if(sn < 1 || sn > k){
            cout << "Invalid Stack Number!" << endl;
            return;
        }

        // overflow
        if(freeSpot == -1){
            cout << "Stack Overflow!" << endl;
            return;
        }

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // insert into stack
        arr[index] = data;

        // link to previous top
        next[index] = top[sn-1];

        // update top
        top[sn-1] = index;
    }

    // POP
    int pop(int sn){

        if(sn < 1 || sn > k){
            cout << "Invalid Stack Number!" << endl;
            return -1;
        }

        // underflow
        if(top[sn-1] == -1){
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        // get top index
        int index = top[sn-1];

        // move top
        top[sn-1] = next[index];

        // add index back to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    // Destructor
    ~kStacks(){
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main(){

    kStacks st(10, 3);

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);

    cout << "Popped from Stack 1: " << st.pop(1) << endl;
    cout << "Popped from Stack 2: " << st.pop(2) << endl;

    return 0;
}