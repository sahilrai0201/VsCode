#include<iostream>
using namespace std;

class Animal{

    public:
    int age;

    void speak(){
        cout << "speaking" << endl;
    }
};

class Dog : public Animal{

    public:
    void bark(){
        cout << "dog barks" << endl;
    }
};

int main(){

    Dog d1;
    d1.speak();
    d1.bark();

    return 0;
}