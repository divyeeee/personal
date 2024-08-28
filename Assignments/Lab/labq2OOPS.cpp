/*To calculate average of numbers using arrays and to display largest element of an array. To add two matrix using multi-
dimensional arrays.*/

#include <iostream>
using namespace std;
void arrayAvg(){
    int size=0,sum=0,max=0;
    cout<<"Enter the size of the array \n";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array \n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
        sum=sum+arr[i];
        if(arr[max]<arr[i])
        max=i;
    }
    cout<<"The average of the array is : "<<(sum*1.0/size)<<endl;
    cout<<"The largest element in the array is : "<<arr[max]<<endl;
}
void matriceOps(){
    int size=0,r1,c1,r2,c2;
    cout<<"Enter number of rows and columns in the first matrix\n";
    cin>>r1>>c1;
    cout<<"Enter number of rows and columns in the second matrix\n";
    cin>>r2>>c2;
    if(r1==r2 && c1==c2){       cout<<"Enter the elements of the first matrix\n";
       int arr1[r1][c1];
       for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++)
        cin>>arr1[i][j];
       }
       cout<<"Enter the elements of the second matrix\n";
       int arr2[r2][c2];
       for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++)
        cin>>arr2[i][j];
       }
       cout<<"The sum of the two matrices is :\n";
       for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++)
        cout<<arr1[i][j]+arr2[i][j]<<" ";
        cout<<endl;
       }
    }
    else{
        cout<<"Matrices do not have the same dimensions and therefore cannot be added.\n";
    }
}
int main(){
    int choice=0;
    int opt=0;
    while(opt==0){
        cout<<"Enter 1 for first operation , 2 for second operation: \n";
        cin>>choice;
        switch (choice)
        {
        case 1: arrayAvg();
            break;
        case 2: matriceOps();
            break;
        default:
            break;
        }
        cout<<"Enter 0 to continue:\n";
        cin>>opt;
    }
    return 0;
}