//FUNCTION OVERLOADING - Compile time polymorphism

#include<iostream>
using namespace std;

class A{

    public:
    void greet(){
        cout << "Hello ji" << endl;
    }

    int greet(char name){
        cout << "Hi jordan" << endl;
        return 1;
    }

    void greet(string name){
        cout << "Bye" << endl;
    }
};

int main(){

    A object;
    object.greet();

    return 0;
}