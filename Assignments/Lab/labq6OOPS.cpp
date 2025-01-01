#include <iostream>
using namespace std;
class S2;  

class S1 {
    int I1;

public:
    S1() : I1(751) {}
    friend class S2;
    friend void comp(S1&, S2&);
};
class S2 {
    int I2;
public:
    S2() : I2(93) {}
    void compare(S1& obj1) {
        if (obj1.I1 > I2)
            cout << "S1's number (" << obj1.I1 << ") is greater." << endl;
        else
            cout << "S2's number (" << I2 << ") is greater." << endl;
    }

    friend void comp(S1&, S2&);
};
void comp(S1& obj1, S2& obj2) {
    if (obj1.I1 > obj2.I2)
        cout << "S1's number (" << obj1.I1 << ") is greater." << endl;
    else
        cout << "S2's number (" << obj2.I2 << ") is greater." << endl;
}


int main() {
    S1 obj1;
    S2 obj2;
    std::cout<<" Using compare function inside B to compare"<< endl;
    obj2.compare(obj1);
    std::cout<<"Using comp freind function to compare"<<endl;
    comp(obj1, obj2);

    return 0;
}