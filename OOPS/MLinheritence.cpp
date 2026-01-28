#include<iostream>
using namespace std;

class Animal{
    public:
    void speak(){
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout << "Barking" << endl;
    }
};

class Lebra : public Dog{
    public:
    void walk(){
        cout << "Walking" << endl;
    }  
};

int main(){
    Lebra l1;
    l1.walk();
    l1.bark();
    l1.speak();

    return 0;
}