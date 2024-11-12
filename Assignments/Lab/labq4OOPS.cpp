
#include <iostream>
using namespace std;
class Rectangle{
    public:
    double len;
    double bre;
    double area;
    Rectangle(){
        double len=1.0;
        double bre=1.0;
    }
    Rectangle(double l,double b){
        len=l;
        bre=b;
        area=l*b;
    }
    Rectangle friend operator+(Rectangle a, Rectangle b);
    };
    Rectangle operator+(Rectangle a,Rectangle b){
        Rectangle c;
        c.len= a.len+b.len;
        c.bre= a.bre+b.bre;
        return c;
    }
int add(int a,int b){
    int area=a*b;
    return area;
}
double add(double a, double b){
    double area=a*b*1.0;
    return area;
}
int main(){
    int l1,b1,l2,b2;
    cout<<"Enter the length and breadth of the first rectangle\n";
    cin>>l1>>b1;
    cout<<"Enter the length and breadth of the second rectangle\n";
    cin>>l2>>b2;
    Rectangle rec1(l1,b1);
    Rectangle rec2(l2,b2);
    Rectangle rec3;
    rec3=rec1+rec2;
    cout<<"Sum of the length and breadth of the rectangles is "<<rec3.len<<" and "<<rec3.bre<<endl;

    double area1=0.0;
    int area2=0;
    double l3,b3=0.0;
    cout<<"Enter length, breadth of the rectangle to calculate area in int\n";
    cin>>l1>>b1;
    area1=add(l1,b1);
    cout<<"Area in int is "<<area1;
    cout<<"\nEnter length, breadth of the rectangle to calculate area in double\n";
    cin>>l3>>b3;
    area2=add(l3,b3);
    cout<<"Area in double is \n"<<area2;
}