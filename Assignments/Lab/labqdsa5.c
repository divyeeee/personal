//Implement following  sorting algorithms to sort an array
//Using merge sort
//using quick sort
//Also analyse best, worst and average case of time complexity and space complexity
#include <stdio.h>
#include <stdlib.h>
int* merging(int* arr,int size,int lstart,int lend,int rstart,int rend){

int size1=lend-lstart+1,size2=rend-rstart+1;
int *arr2=(int *)malloc((size1+size2)*sizeof(int)) ;  
int i=lstart,j=rstart,k=0;
while(i!=lend &&j!=rend){
if(arr[i]<arr[j]){
    arr2[k++]=arr[i++];
}
else{
    arr2[k++]=arr[j++];
}
}
while(i!=lend){
    arr2[k++]=arr[i++];
}
while(j!=rend){
    arr2[k++]=arr[j++];
}
return arr2;
}
int* mergeSort(int* arr,int size,int start,int end){
    int left=0,right=0;
if(start==end){
    return start;
}
int mid=start+(end-start)/2;
int lstart=start,lend=mid-1,rstart=mid+1,rend=end,sizel=mid-start+1,sizer=end-mid+1;
left=mergeSort(arr,sizel,lstart,lend);
right=mergeSort(arr,sizer,rstart,rend);
arr=merging(arr,size,le)
}
void quickSort(int* arr,int size){

}
int main(){
    return 0;
}

