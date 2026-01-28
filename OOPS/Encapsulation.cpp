#include<iostream>
#include<cstring>
using namespace std;

class Student {

    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main(){

    Student first;
    
    cout << endl;
    cout << "Everything is going good" << endl;
    cout << endl;

    return 0;
}