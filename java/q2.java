//this is a code for binarysearch in  strictly sorted matrix 
import java.util.*;
public class q2
{
    static int[] binsrch(int row,int arr[],int Rst,int Rend,int key)
    {
        int start=Rst,end=Rend;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==key)
            {
                return new int[]{row,mid};
            }
            else if(arr[mid]<key)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return new int[]{-1,-1};
    }
    static int[]  search(int[][] arr, int key)
    {
        int row=arr.length;
        int Rst=0,Red=row-1;
        int Rcol=(arr[0].length-1)/2;
        if(row==1)
        {
            return binsrch(0,arr[0],0,arr[0].length-1,key);
        }
        while(Rst<Red-1)
        {
           int Rmid=Rst+(Red-Rst)/2;
           if(arr[Rmid][Rcol]==key)
           {return new int[]{Rmid,Rcol};}
           else if(arr[Rmid][Rcol]<key){
            Rst=Rmid;
           }
           else{
            Red=Rmid;
           }
        }
        System.out.println(Rst+""+Red+""+Rcol);
        //now we have zoomed in on the two rows that might contain our key
        if(arr[Rst][Rcol]==key)
        {
            System.out.println("True1");return new int[]{Rst,Rcol};
           }
        else if(arr[Rst][Rcol]>key)
        { System.out.println("True2");return binsrch(Rst,arr[Rst],0,Rcol-1,key);}
        else if(arr[Rst][arr[0].length-1]>key)
        { System.out.println("True2");
        return binsrch(Rst,arr[Rst],Rcol+1,arr[0].length-1,key);
        }
        else if(arr[Red][Rcol]==key)
        { System.out.println("True3");
        return new int[]{Red,Rcol};}
        else if(arr[Red][Rcol]>key)
        { System.out.println("True4");
        return binsrch(Red,arr[Red],0,Rcol-1,key);}
        else if(arr[Red][arr[0].length-1]>key)
        { System.out.println("True5");
        return binsrch(Red,arr[Red],Rcol+1,arr[0].length-1,key);}
        else 
        { System.out.println("True6");
        return new int[]{-1,-1};}
    }
    public static void main(String args[])
    {
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter the number of rows");
      int row=sc.nextInt();
      System.out.println("Enter the number of columns");
      int column=sc.nextInt();
      System.out.println("Enter the elements");
      int arr[][]=new int[row][column];
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<column;j++)
        {
           arr[i][j]=sc.nextInt();
        }
      }
      System.out.println("Enter the key");
      int key=sc.nextInt();
      System.out.println("Key is at: "+Arrays.toString(search(arr,key)));
    }
}