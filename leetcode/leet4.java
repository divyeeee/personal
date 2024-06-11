//54. Spiral Matrix

import java.util.ArrayList;

class P54{
    public static ArrayList<Integer> spiralOrder(int[][] arr){
        int n=arr.length;
        int m=arr[0].length;
        int num=0,i=0,j=0,k=m*n,n1=n,m1=m;
        ArrayList<Integer> list=new ArrayList<Integer>(k);
        outer:
        while(m>0 && n>0){
            //
            
            for(;j<m;j++){
            list.add(arr[i][j]);
            num++;
            if(num>=k)
            break outer;}
            //
            j--;
            i++;
            for(;i<n;i++){
                list.add(arr[i][j]);num++;
            if(num>=k)
            break outer;}
            //
            i--;
            j--;
            for(;j>=k/n1-m;j--){
                list.add(arr[i][j]);num++;
                if(num>=k)
            break outer;}
            //
            j++;
            i--;
            for(;i>k/m1-n;i--){
                list.add(arr[i][j]);num++;
                if(num>=k)
            break outer;}
            //
            i++;
            j++;
            n--;
            m--;
        }
        return list;
    }
    public static void main(String args[]){
        int arr[][]={
            {1,2,3,4},
        {5,6,7,8},
    {9,10,11,12},
{13,14,15,16}};
            ArrayList<Integer> list=new ArrayList<Integer>(arr.length*arr[0].length);
        list=spiralOrder(arr);
        System.out.println(list);
    }
}