/* 3152. Special Array-2 */ 
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
class P3152{
    public boolean[] isArraySpecial(int[] nums,int[][] queries){
        boolean res[]=new boolean[queries.length];
        int k=0;
        for(int query[]:queries){
            for(int i=query[0];i<query[1];i++){
                if((nums[i] & 1) == (nums[i+1] & 1)){
                    res[k]=true;
                    break;
                }
            }
            k++;
        }
        for(int i=0;i<res.length;i++){
            res[i]=!res[i];
        }
        return res;
    }

public static void main(String args[]){
    P3152 obj=new P3152();
    Scanner sc=new Scanner(System.in);
    int[] nums={10,8,8,9};
    int queries[][]={{2,3},{0,1},{2,3},{1,3},{2,2}};
    System.out.println(Arrays.toString(obj.isArraySpecial(nums, queries)));
}
}