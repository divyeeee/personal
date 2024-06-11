//this is an implementation of binary search in 2d by using such function from class binarysearch
import java.util.Scanner;
public class implement {
   public static void main(String args[])
   {
      Scanner sc=new Scanner(System.in);
      System.out.println("Enter the number of rows as well as columns");
      int row=sc.nextInt();
      int col=sc.nextInt();
      int arr[][]=new int[row][col];
      System.out.println("Enter elements of the matrix");
      for(int i =0;i<row;i++){
        for(int j=0;j<col;j++)
        {
          arr[i][j]=sc.nextInt();
        }
        }
        System.out.println("Enter the key");
        int key=sc.nextInt();
        String res=binarysearch.binary2dSearch(arr, row, col, key);
        System.out.println(res);
   }
}
