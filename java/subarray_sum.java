// This program displays a boolean table to indicate various sum and if the corresponding subset exists or not to make that sum.
// import java.util.*;
class subarray_sum
{
    public static void subarr_count(int[] arr,int w){
        w=w+1;
        int n=arr.length+1;
        boolean t[][]=new boolean[n][w];
        for(int i=0;i<n;i++){
            for(int j=0;j<w;j++){
                if(j==0){
                    t[i][j]=true;
                }
                else if(i==0){
                    t[i][j]=false;
                }
            }
        }
        display(t);
        // now filling up other spaces in the matrix
        for(int i=1;i<n;i++){
            for(int j=1;j<w;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        display(t);


    }
    public static void display(boolean[][] arr){
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                if(arr[i][j]){
                System.out.print("  "+arr[i][j]);}
                else{
                    System.out.print(" "+arr[i][j]);
                }
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int arr[]={1,2,3,8};
        subarr_count(arr,11);
    }
}