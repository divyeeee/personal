/*Given an array X. Compute the array A such that A[i] is the average of elements X[0]. . . X[i], for i = 0....n − 1. You can solve
this with two methods, one with O(n2) and one with O(n) time complexities. Compare time complexities of both the methods
by experimental approach plotting graph between ‘n’ and time taken for execution*/
#include <stdio.h>
void avg_n2(float arr[], int n){
    float Arr[n]; // declaration of the array storing the average for the first algorithm (complexity n^2)
for(int i=0;i<n;i++){   //counter for storing the average 
        int sum=0;  // stores the sum of the elements from 0 to ith element, initialized to 0 after the second loop is finished 
      for(int j=0;j<=i;j++)
        sum=sum+arr[j];
        Arr[i]=(sum*1.0)/(i+1); // storing the array in another array
      }
      printf("Averages------>\n");
    for(int i=0;i<n;i++){
        printf("%f \n",Arr[i]);// printing the elements of the array Arr
}
}
void avg_n(float arr[],int n){
 int sum=0; // in this algorithm the sum variable won't be initialized again and again , thus stores the sum of elements until the ith iteration 
    for(int i=0;i<n;i++){
      sum=sum+arr[i];
      arr[i]=(sum*1.0)/(i+1);// rewriting the array to avoid making another one 
    }
    printf("Averages------>\n"); // printing the average values stored in the array
    for(int i=0;i<n;i++){
        printf("%f \n",arr[i]);
    }
}
int main(){ // starting the main question
    int n=0;// number of elements to be entered in the array
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    float arr[n]; // declaration of the array storing the elements given by the user
    //float Arr[n]; // declaration of the array storing the average for the first algorithm (complexity n^2)
    printf("Enter the elements of the array.\n");
    for(int i=0;i<n;i++){  // taking input into the array
        scanf("%f",&arr[i]);
    }
    printf("Average using the algorithm with n^2 time complexity\n");
   avg_n2(arr,n);
    printf("Average using the algorithm with n time complexity\n");  
   avg_n(arr,n);
    }
