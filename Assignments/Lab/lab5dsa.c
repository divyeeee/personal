/*Experiment 5
Implement following sorting algorithms to sort an array (make a dynamic array):
1.	Write a function to sort an array using Selection sort.
2.	Write a function to sort an array using Insertion sort.
Analyze best, average and worst case time complexity of both sorting algorithms.*/
#include <stdio.h>
void selSort(int *arr,int size){
    int steps=0;
    for(int i=0;i<size;i++){
        int max=0;
        for(int j=0;j<size-i;j++){
            steps++;
            if(arr[max]<arr[j]){
            
            max=j;}
        }
        int t=arr[size-i-1];
    arr[size-i-1]=arr[max];
    arr[max]=t;
    }
    printf("Steps taken by Selection Sort - %d", steps);
}
void inSort(int *arr,int size){
    int steps=0;
    for(int i=1;i<size;i++){
            int j=i-1;
            while(j>=0 && arr[j+1]<arr[j]){
                int t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
                j--;
                steps++;
            }
        }
    
    printf("Steps taken by Insertion Sort - %d", steps);
}
int main(){
    int size=0;
    printf("Enter the size of your array\n");
    scanf("%d", &size);
    printf("Enter the elements of your array\n");
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    int arrcopy[size];
    for(int i=0;i<size;i++){
        arrcopy[i]=arr[i];
    }
    printf("Sorting through Selection Sort -->\n");
    selSort(arr,size);
    printf("Sorted array by Selection Sort -->\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("Sorting through Insertion Sort -->\n");
    inSort(arrcopy,size);
    printf("Sorted array by Insertion Sort -->\n");
    for(int i=0;i<size;i++){
        printf("%d ",arrcopy[i]);
    }
}