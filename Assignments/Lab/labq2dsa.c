#include <stdio.h>
#include <stdbool.h> 
#include <cstdlib>
void print(int *arr ,int size){
    for(int i=0;i<size;i++){
    printf("%d ",arr[i]);}
}

void bubSort(int arr[], int size){
    printf("Array before sorting-->");
 print(arr,size);
 int steps=0;
    for(int i=0;i<size-1;i++){
        bool check=false;
        
        for(int j=0;j<size-1-i;j++){
            steps++;
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                check=true;
            }
        }
        if(!check)
        break;
    }
    printf("\nArray after sorting-->");
    print(arr,size);
    printf("Steps--> %d",steps);
}

int main(){
 int size=0;
 printf("Enter the size of your array");
 scanf("%d",&size);
 int *arr= (int*)malloc(size * sizeof(int));

 printf("Enter the elements of the array");
 for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
 }
 
 bubSort(arr,size);
return 0;
}