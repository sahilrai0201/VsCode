//OPERATOR OVERLOADING - Compile time polymorphism

#include<iostream>
using namespace std;

class Number{
    public:
    int value;
    Number(int v = 0){
        value = v;
    }
    //overlaoding '+' operator to perform subtraction
    Number operator + (const Number& obj){
        return Number(value - obj.value);    //subtraction
    }
};

int main(){
    Number n1(20);
    Number n2(5);
    Number result = n1+n2;   //'+' will perform n1-n2
    cout << "Result = " << result.value << endl;
    return 0;
}