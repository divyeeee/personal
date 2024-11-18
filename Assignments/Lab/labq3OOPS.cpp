#include <iostream>
using namespace std;
class Student{
    int roll_no;
    string name;
    public:
    void getData();
    void putData();
};
void Student::getData(){
cout<<"Enter your roll number and name"<<endl;
cin>>roll_no>>name;
}
void Student::putData(){
cout << roll_no << " ";
  cout << name << " ";
  cout << endl;
}
void displayArray(int* arr,int size){
    for(int i=0;i<size;i++){
        cout<<"Element at "<<i<<" : "<<*(arr+i)<<endl;
    }
}
int main(){
    cout<<"Task 1:"<<endl;
    int n=0;
    cout<<"Enter the number of students--";
    cin>>n;
    Student *stu=new Student[n];
    for(int i=0;i<n;i++){
        stu[i].getData();
    }
    for(int i=0;i<n;i++){
        cout<<"hi ";
        stu[i].putData();
    }
    cout<<"Task 2:"<<endl;
    int size=0;
    cout<<"Enter the size of the array--";
    cin>>size;
    int arr[n];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int target=0,steps=0;bool flag=false;
    cout<<"Enter target to be searched"<<endl;
    cin>>target;
    cout<<"Searching using linear search--"<<endl;
    for(int i=0;i<size;i++){
        steps++;
        if(arr[i]==target){
            flag=true;
        cout<<"Element found at index--"<<i<<endl;
        cout<<"Steps taken--"<<steps<<endl;
        break;
        }
    }
    if(!flag)
    cout<<"Element not found"<<endl;
    flag=false;
    steps=0;
    cout<<"Searching using binary search--"<<endl;
    int start=0,end=size-1,mid=0;
    while(start<=end){
        mid=start+(end-start)/2;
        steps++;
        if(arr[mid]==target){
            flag=true;
            cout<<"Element found at index--"<<mid<<endl;
        cout<<"Steps taken--"<<steps<<endl;
        break;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(!flag)
    cout<<"Element not found"<<endl;

    cout<<"Task 3"<<endl;
    string str="Divye";
    cout<<"[";
    for(int i=0;i<str.size();i++){
        if(i!=str.size()-1)
     cout<<str[i]<<",";
     else
     cout<<str[i]<<"]"<<endl;
    }
    cout<<"Task 4"<<endl;
    size=0;
    cout<<"Enter the size of the array :";
    cin>>size;
    int arr2[size];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<size;i++){
        cin>>arr2[i];
    }
    displayArray(arr2,size);

}