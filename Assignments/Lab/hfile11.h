// write a user- defined header file that contains function to calculate average of elements of an array and find the maximum in an array 
// and include this header file in your main program to use these functions
// code for the header file
#include <iostream>
using namespace std;
int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
float avg(int arr[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum / n;
}
