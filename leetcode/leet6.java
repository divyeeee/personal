//136. Single Number
class P136{
    //using insertion sort, we sort the array and then find the element that does not have a double
    public static int single(int[] nums)
    {
        for(int i=0;i<nums.length-1;i++)
        {
            int j=i+1;
            while(j>0){
                if(nums[j-1]>nums[j]){
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                }j--;
            }
        }
        int i=0;
        for(;i<nums.length-1;i=i+2){
            if(nums[i]!=nums[i+1])
            break;
        }
        return nums[i];
    }
    //now using bubble sort
    public static int single2(int []nums){
        boolean swapped=false;
      for (int i = 0; i < nums.length; i++) {
        for (int j = 1; j < nums.length-i; j++) {
                if(nums[j-1]>nums[j]){
                    int temp=nums[j-1];
                    nums[j-1]=nums[j];
                    nums[j]=temp;
                    swapped=true;
            }
        }
        if(!swapped)
        break;
      }
      int i=0;
        for(;i<nums.length-1;i=i+2){
            if(nums[i]!=nums[i+1])
            break;
        }
        return nums[i];
    }
    //using a very optimized solution
    public static int optimized(int[] arr){
        int element=0;
        for (int i = 0; i < arr.length; i++) {
            element=arr[i]^element;
        }
        return element;
    }
    public static void main(String[] args) {
        int arr[]={4,1,2,1,2,4,6};
        System.out.println("The integer is : "+optimized(arr));
    }
}