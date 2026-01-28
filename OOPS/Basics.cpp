#include<iostream>
#include<cstring>
using namespace std;

class Hero {       //class creation

    //properties or data members
    private:
    int health;

    public:
    char *name;
    char level;

    static int timeToComplete;

    Hero(){
        cout << "constructor called!" << endl;
        name = new char[100];
    }

    //parameterized constructor
    Hero(int health){
        // cout << "this : " << this << endl;
        this -> health = health;
    }

    Hero(int health, char level){
        // cout << "this : " << this << endl;
        this -> health = health;
        this -> level = level;
    }

    //copy constructor
    Hero(Hero& temp){

        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        
        cout << " copy constructor called!" << endl;
        this->health = temp.health;
        this->level = temp.level;
    } 

    void print(){
        cout << "[Name : " << this->name << ", ";
        cout << "health : " << this->health << ", ";
        cout << "level : " << this->level << " ]" << endl;
    }

    int getHealth(){
        return health;
    }
    int getLevel(){
        return level;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
    void setName(char name[]){
        strcpy(this->name, name);
    }

};

int Hero::timeToComplete = 5; 

int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[6] = "SAHIL";
    hero1.setName(name);

    // hero1.print();

    //use default copy constructor - comment default copy constructor!
    Hero hero2(hero1);
    // hero2.print();

    hero1.name[0] = 'T';
    hero1.print();

    hero2.print();     //problem arises here - previously name was sahil but its printing tahil now for hero2

    hero1 = hero2;
    hero1.print();
    hero2.print();

    // Hero S(70, 'C');
    // S.print();

    // //copy constructor
    // Hero R(S);
    // R.print();

    // Hero ramesh(10);
    // cout << "address of ramesh : " << &ramesh << endl;
    // ramesh.getHealth();

    // Hero temp(22, 'B');
    
    // //object creation - static allocation
    // Hero a;

    // a.setLevel('A');
    // a.setHealth(80);

    // cout << "level of a is : " << a.level << endl;
    // cout << "health of a is : " << a.getHealth() << endl;

    // //dynamically
    // Hero *b = new Hero;

    // b->setLevel('B');
    // b->setHealth(70);

    // cout << "level of b is : " << (*b).level << endl;
    // cout << "health of b is : " << (*b).getHealth() << endl;

    // cout << "level of b is : " << b->level << endl;
    // cout << "health of b is : " << b->getHealth() << endl;

    // // cout << "Ramesh health is : " << Ramesh.getHealth() << endl;
    // // Ramesh.setHealth(70);
    // // Ramesh.level = 'A';

    // // cout << "health is : " << Ramesh.getHealth() << endl;
    // // cout << "level is : " << Ramesh.level << endl;

    return 0;
}