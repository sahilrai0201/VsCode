//METHOD OVERRIDNG - Run time polymorphism

#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout << "Speaks" << endl;
    }
};

class Dog : public Animal{
    public:
    void speak() override{           //method overriding
        cout << "Barks" << endl;
    }
};

class Cat : public Animal{
    public:
    void speak() override{           //method overriding
        cout << "Meows" << endl;
    }
};

int main(){

    Dog d;
    Cat c;
    d.speak();
    c.speak();

    return 0;
}