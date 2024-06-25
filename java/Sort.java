//code for bubble sort
import java.util.Scanner;
class Sort
{
    public static int[] bubblesort(int[] arr,String str){
        int size=arr.length;
        boolean swapped;
        if(str.toLowerCase().equals("ascending"))
        {
            
            for(int i=0;i<size;i++)
            {swapped=false;
                for(int j=1;j<size-i;j++)
                {
                    if(arr[j-1]>arr[j])
                    {
                        int temp=arr[j-1];
                        arr[j-1]=arr[j];
                        arr[j]=temp;
                        swapped=true;
                    }
                }
                if(!swapped){
                    break;
                }
            }
        }
        if(str.toLowerCase().equals("descending"))
        {
            
            for(int i=0;i<size;i++)
            {swapped=false;
                for(int j=1;j<size-i;j++)
                {
                    if(arr[j-1]<arr[j])
                    {
                        int temp=arr[j-1];
                        arr[j-1]=arr[j];
                        arr[j]=temp;
                    }
                }
                if(!swapped)
                break;
            }
        }
        return arr;
    }
    public static int[] selectionsort(int[] arr,String str)
    {
        int size=arr.length;
        if(str.toLowerCase().equals("ascending"))
        {
        for(int i=0;i<size;i++)
        {
            int max=0;
            for(int j=1;j<size-i;j++)
            {
                if(arr[max]<arr[j])
                max=j;
            }
            int temp=arr[size-i-1];
            arr[size-i-1]=arr[max];
            arr[max]=temp;
        }}
        else{
            for(int i=0;i<size;i++)
        {
            int min=0;
            System.out.println("Minimum:before"+min);
            for(int j=0;j<size-i;j++)
            {
                if(arr[min]>arr[j])
                min=j;
            }
            System.out.println("Minimum:"+min+"arr[4]="+arr[3]);
            int temp=arr[size-1-i];
            arr[size-1-i]=arr[min];
           arr[min]=temp;
            System.out.println("Minimum:"+min+"arr[1]="+arr[1]+"arr[4]:"+arr[3]);
        }
        }
        return arr;
    }
    static int[] insertionsort(int[] arr,String str){
        if(str.toLowerCase().equals("ascending"))
        {
            for(int i=0;i<arr.length-1;i++){
                int j=i+1;
                while(j>0){
                    if(arr[j-1]>arr[j]){
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;}
                    j--;
            }
            }
        }
        else{
            for(int i=0;i<arr.length-1;i++){
            int j=i+1;
            while(j>0){
                if(arr[j-1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;}
                j--;
        }
    }
}
        return arr;
}
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int arr[]=in.input();
        System.out.println("Select the sort order");
        String str=sc.nextLine();
        arr=insertionsort(arr, str);
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
            sc.close();
        }

    }
}