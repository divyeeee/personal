//bubble sort using recursion

import java.util.Arrays;

class vid29_Q3_Q4{
    public static void main(String[] args) {
        int arr[]={4,1,5,2,3,6};
        selectSort(arr, arr.length, 0,0);
        System.out.print(Arrays.toString(arr));

    }
    static int[] swap(int arr[],int j,int j1){
        int temp=arr[j];
        arr[j]=arr[j1];
        arr[j1]=temp;
        return arr;
    }
    static void bubSort(int arr[],int i,int j){
      if(i==0)
      return ;
      if(j<i){
        if(arr[j]>arr[j+1]){
            swap(arr, j, j+1);
        }
        bubSort(arr, i, j+1);
      }
      else{
        bubSort(arr, i-1, 0);
      }
    }
    static void selectSort(int arr[],int i,int j,int max){
      if(i==0)
      return ;
      if(j<i){
        if(arr[j]>arr[max]){
            max=j;
        }
        selectSort(arr, i, j+1, max);
      }
      else{
        swap(arr, i-1, max);
        max=0;
        selectSort(arr, i-1, 0, max);
      }
    }
}