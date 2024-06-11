//27. Remove Element
class P27
{
   
    public static int insertionsort(int[]nums,int val)
    {
        if(nums.length==0)
            return 0;
        if(nums.length==1)
        {if(nums[0]==val)
         return 0;
        else
         return 1;}
        for(int i=0;i<nums.length-1;i++){
            int j=i+1;
            if(nums[j]==val)
            continue;
            while(j>0){
                if(nums[j-1]>nums[j] || nums[j-1]==val){
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                } j--;
                
            }
        }
        int i;
        for (i=0;i<nums.length;i++)
            if(nums[i]==val)
                break;
        
return i;
    }
    public static void main(String[] args) {
        int nums[]={3,3};
        int k=insertionsort(nums, 5);
        for (int i = 0; i <k; i++) {
            System.out.println(nums[i]);
        }
    }
    
}