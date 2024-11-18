// code for quick sort

import java.util.Arrays;

class quicksort{
    public static void main(String args[]){
     int arr[]={3,1,4,2,5};
     sort_quick(0, arr.length-1, arr);
     System.out.println(Arrays.toString(arr));
    }
    public static void sort_quick(int low, int high,int[] arr){
        if(high<low)
        return;
        int s=low;
        int e=high;
        int pivot=s+(e-s)/2;
        while(s<=e){
            while(arr[s]<arr[pivot])
            s++;
            while(arr[e]>arr[pivot])
            e--;
            if(s<=e){
                int temp=arr[s];
                arr[s]=arr[e];
                arr[e]=temp;
                s++;
                e--;
            }
        }
        sort_quick(low, e, arr);
        sort_quick(s,high, arr);
    }
}