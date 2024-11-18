
// **Q. 1)** Write a program to divide two numbers and use try-catch statements to handle exceptions  
// a) 1/0 → Infinity  
// b) 0/0 → Not defined  

// **Q. 2)**  
// **2.1)** Create four vectors  
// a) Predefined set of values ({1, 0, 3, 4, 5})  
// b) Of size 5  
// c) Of size 5 with all values initialized to 0  
// d) An exact copy of vector c  

// **2.2)**  
// In vector c, insert value 5 at the end and then remove 2 values from the end.
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

void exception_handling(){
    double num1, num2, result;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    try{
        if(num2==0){
            if(num1==0){
                throw invalid_argument("0/0 is not defined");
            }
            else if(num1==1){
                throw overflow_error("1/0 is infinity");
            }
        }
        float result=num1/num2;
        cout<<"The result is -"<<result<<endl;
    }
    catch (invalid_argument &e){
        cout<<"Error:"<<e.what()<<endl;
    }
    catch (overflow_error &e){
        cout<<"Error:"<<e.what()<<endl;
    }

}
void vectors() {
    // 2.1 Create four vectors
    vector<int> vecA = {1, 0, 3, 4, 5}; // Predefined set of values
    vector<int> vecB(5);                // Of size 5 (default initialized)
    vector<int> vecC(5, 0);             // Of size 5 with all values initialized to 0
    vector<int> vecD(vecC);             // Exact copy of vector C

    // Output for verification
    cout << "Vector A: ";
    for (int val : vecA) cout << val << " ";
    cout << endl;

    cout << "Vector B: ";
    for (int val : vecB) cout << val << " ";
    cout << endl;

    cout << "Vector C before modification: ";
    for (int val : vecC) cout << val << " ";
    cout << endl;

    // 2.2 Insert value 5 in vector C and remove last two elements
    vecC.push_back(5);  // Insert value 5 at the end
    cout << "Vector C after modification 1: ";
    for (int val : vecC) cout << val << " ";
    cout << endl;
    vecC.pop_back();    // Remove last element
    vecC.pop_back();    // Remove second last element

    // Output modified vector C
    cout << "Vector C after modification 2: ";
    for (int val : vecC) cout << val << " ";
    cout << endl;
}
int main(){
    // exception_handling();
    vectors();
}