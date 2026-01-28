#include<iostream>
using namespace std;

class Animal{
    // public:
    // int age;
    // int weight;

    public:
    void bark(){
        cout << "barking" << endl;
    }
};

class Human{
    // public:
    // string color;

    public:
    void speak(){
        cout << "speaking" << endl;
    }
};

//multiple inheritence
class Hybrid : public Animal, public Human{

};

int main(){
    Hybrid obj1;
    obj1.bark();
    obj1.speak();

    return 0;
}