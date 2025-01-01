//code for the main program to use the functions from the header file for averade of all elements of an array and to find the maximum element of an array
#include <iostream>
#include "hfile11.h"
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The average of all elements of the array is: " << avg(arr, n) << endl;
    cout << "The maximum element of the array is: " << max(arr, n) << endl;
    return 0;
}