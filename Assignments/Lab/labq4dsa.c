#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
elementInsert(int *arr,int index,int size,int element){
    arr=(int*)realloc(arr,(size+1)*sizeof(int));
    for(int i=size;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=element;
    printf("\nInserting the element....");
    printf("\nDisplaying the Array\n");
        for(int i=0;i<size+1;i++){
            printf("%d ",arr[i]);
        }
}

elementDelete(int *arr,int index,int size){
    
    int t=0;
    for(int i=index;i<size-1;i++){
      arr[i]=arr[i+1];
    }
    arr=(int*)realloc(arr,(size-1)*sizeof(int));
    printf("\nDeleting the element....");
    printf("\nDisplaying the Array\n");
        for(int i=0;i<size-1;i++){
            printf("%d ",arr[i]);
        }
}
binSearch(int *arr,int size,int element){
    int start=0,end=size-1,mid=0;
    while(start<=end){
        mid=start+(end-start)/2;
        if(element==arr[mid])
        {
            printf("Element found at-- %d",mid);
            elementDelete(arr,mid,size);
            return 0;
        }
        else if(element<arr[mid]){
           end=mid-1;
        }
        else{
          start=mid+1;
        }
    }
    if(mid==0 || arr[mid]>element){
        printf("Element inserted at-- %d",mid);
    elementInsert(arr,mid,size,element);
    }else if(arr[mid]<element){
    printf("Element inserted at-- %d",mid+1);
    elementInsert(arr,mid+1,size,element);}
}
    int main(){
        int* arr;
        int size=0;
        int element=0;
        printf("Enter the size of the array---");
        scanf("%d",&size);
        printf("Enter the elements in the array\n");
        arr=(int*)malloc(size*sizeof(int));
        for(int i=0;i<size;i++){
            scanf("%d",&arr[i]);
        }
        printf("Displaying the Array\n");
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\nEnter the element to be found\n");
        scanf("%d",&element);
        binSearch(arr,size,element);
        free(arr);
    }