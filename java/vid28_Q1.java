import java.util.ArrayList;

class vid28_Q1
{
    static ArrayList<Integer> list=new ArrayList<>(10);
    public static void main(String[] args){
        int arr[]={1,2,3,4,6,6,8,5,6};
     //System.out.println(isSorted(arr,0));
     //System.out.println(linSearch(arr, 6, 0));
     //list_sorted(arr, 0, 6);
     //System.out.println(list);
     System.out.println(list_sort_ret(arr, 6, 0, list));
    }
    //checks if the array is sorted or not

    public static boolean isSorted(int arr[],int i){
        if(i==arr.length-1)
           return true;
        return arr[i]<arr[i+1] && isSorted(arr,i+1);
    }
    //linear search using recursion
    public static boolean linSearch(int arr[],int target,int i){
        if(i==arr.length-1)
        return (arr[i]==target);
        return arr[i]==target || linSearch(arr, target, i+1);
    }
    //storing all the target's indices in an array_list
    static void list_sorted(int arr[], int i, int target){
        if(i==arr.length){
            return;
        }
        if(arr[i]==target)
        list.add(i);
        list_sorted(arr, i+1, target);
    }
    //storing and returning the list of all the target's indices
     static ArrayList<Integer> list_sort_ret(int arr[], int target,int i,ArrayList<Integer> list){
        if(i==arr.length)
        return list;
        if(target==arr[i])
         list.add(i);
        return list_sort_ret(arr, target, i+1, list); 
    }
    //storing the target's indices in list that are inclusive to their own function
    static ArrayList<Integer> list_sort_ret2(int arr[],int i,int target){
        ArrayList<Integer> list=new ArrayList<>(10);
        if(i==arr.length)
        return list;
        if(arr[i]==target)
        list.add(i);
        list.addAll(list_sort_ret2(arr, i+1, target));
        return list;
    }
} 