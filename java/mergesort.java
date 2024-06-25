//code for merge sort

import java.util.Arrays;

class mergesort{
    public static void main(String[] args){
        int arr[]={4,6,5,2,1,3};
       // System.out.println(Arrays.toString(mergeSort(arr)));
        System.out.println(Arrays.toString(mergeSortinPlace(arr,0,arr.length-1)));
    }
    static int[] merge(int first[],int second[]){
        int i=0;
        int j=0;
        int k=0;
        int mix[]=new int[first.length+second.length];
         while(i<first.length && j<second.length){
            if(first[i]<second[j]){
                mix[k]=first[i];i++;
            }
            else{
                mix[k]=second[j];j++;
            }
            k++;
         }//copying the remaining elemnets left in the bigger array
         while(i<first.length){
            mix[k]=first[i];i++;k++;
         }
         while(j<second.length){
            mix[k]=second[j];j++;k++;
         }
         return mix;
    }
    static int[] mergeSort(int arr[]){
        if(arr.length==1)
        return arr;
        
            int mid=arr.length/2;
            int left[]=mergeSort(Arrays.copyOfRange(arr, 0, mid));
            int right[]=mergeSort(Arrays.copyOfRange(arr, mid, arr.length));
        
        return   merge(left, right);
        
    }
    static int[] mergeSortinPlace(int arr[],int start,int end){
        if(start==end){
            return arr;
        }
        int mid=start+(end-start)/2;
        int left[]=mergeSortinPlace(arr, start, mid);
        int right[]=mergeSortinPlace(arr, mid+1, end);
    return merge(left,right);
    }
}