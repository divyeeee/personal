//create a template class containing two generic variables T1 A and T2 B, write default and parameterized contrictor in the class to initialize their values

#include <iostream>
using namespace std;
template <typename T1, typename T2>
// class A{
//     public :
//     T1 a;
//     T2 b;
//     A(){
//         a=0;
//         b=0;
//     }
//     A(T1 x, T2 y){
//         a=x;
//         b=y;
//     }
//     void display(){
//         cout << "a = " << a << endl;
//         cout << "b = " << b << endl;
//     }
// };
// int main(){
//     <B><int, float> obj1;
//     obj1.display();
//     <A><int, float> obj2(10, 20.5);
//     obj2.display();
//     return 0;
    
// }
class A{
    public:
    T1 a;
    T2 b;
    A(){
        a = 0;
        b = 0;
    }
    A(T1 x, T2 y){
        a = x;
        b = y;
    }
    void display(){
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
int main(){
    A<int, float> obj1;
    obj1.display();
    A<string, float> obj2("hi", 20.5);
    obj2.display();
    return 0;
}
