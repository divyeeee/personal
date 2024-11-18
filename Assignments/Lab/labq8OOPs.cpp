#include<iostream>
using namespace std;

class Base {
public:
    Base() { cout << "inside base constructor" << endl; }
    ~Base() { cout << "inside base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "inside derived constructor" << endl; }
    ~Derived() { cout << "inside derived destructor" << endl; }
};

int main() {
    Derived d;
    return 0;
}