class P1800 {
    public static int maxAscendingSum(int[] nums) {
        int sum=0,maxsum=nums[0];
        boolean flag=false;
        for(int i=0;i<nums.length-1;i++){
            if(!flag)
            sum=nums[i];
            if(nums[i]<nums[i+1]){
            sum+=nums[i+1];
            flag=true;
            }
            else{
                flag=false;
                maxsum=Math.max(sum,maxsum);
            }
        }
        return Math.max(sum,maxsum);
    }
    public static void main(String args[]){
        int nums[]={10,20,30,5,10,50};
        System.out.println(maxAscendingSum(nums));
    }
}
