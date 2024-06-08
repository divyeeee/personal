//code for input of an array
import java.util.Scanner;
class in{
    public static int[] input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int size=sc.nextInt();
        System.out.println("Enter the elements");
        int arr[]=new int[size];
        for(int i=0;i<size;i++){
           arr[i]=sc.nextInt();
        }
        return arr;
    

    }
}