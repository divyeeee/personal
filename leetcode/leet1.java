//26. Remove Duplicates from Sorted Array
class P26
{
       public static int removeDuplicates(int[] nums) {
            int k=0;
            int i=0;
            int max=nums[nums.length-1];
            while(nums[k]!=max){
                if(nums[k]<nums[i])
                    nums[++k]=nums[i++];
                else
                    i++;
            }
            return k+1;
        }
        public static void main(String[] args) {
            int nums[]={1,1,2};
            int k=removeDuplicates(nums);
            for(int i=0;i<k;i++)
            {
                System.out.println(nums[i]);
            }
        }
}
