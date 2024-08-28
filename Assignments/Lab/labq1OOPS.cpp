#include <iostream>
using namespace std;
void oddEvenBitwise(){
    int a;
    cout<<"Enter a number:";
    cin>>a;
    if(a&1){
        cout<<"Odd"<<endl;
    }
    else{
        cout<<"Even"<<endl;
    }
}
void swapping3var(){
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    cout<<"Before swapping: a="<<a<<" b="<<b<<endl;
    int c=a;
    a=b;
    b=c;
    cout<<"After swapping: a="<<a<<" b="<<b<<endl;
}
void fiboseries(){
    int n;
    cout<<"Enter the number of terms for the series:";
    cin>>n;
    int a=0,b=1,c;
    while(n>0){
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
        n--;
    }
}
/*int fiborec(int n){
    if(n<=1){
        cout<<"0 1 ";
        return 1;
    }


}*/
void quotient_remainder(){
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    int q=a/b;
    int r=a%b;
    cout<<"Quotient: "<<q<<endl;
    cout<<"Remainder: "<<r<<endl;
}
void charASCII(){
    char a;
    cout<<"Enter a character";
    cin>>a;
    cout<<"ASCII value of "<<a<<" is "<<(int)a<<endl;
}
int main(){
    int choice=0;
    int opt=0;
    while(opt==0){
        cout<<"Enter 1 for odd even, 2 for swapping, 3 for fibonacci series, 4 for quotient and remainder, 5 for ASCII value of a character:";
        cin>>choice;
        switch (choice)
        {
        case 1: oddEvenBitwise();
            break;
        case 2: swapping3var();
            break;
        case 3: fiboseries();
            break;
        case 4: quotient_remainder();
            break;
        case 5: charASCII();
            break;
        default:
            break;
        }
        cout<<"Enter 0 to continue:";
        cin>>opt;
    }
    return 0;
}