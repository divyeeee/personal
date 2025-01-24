//2270. Number of Ways to Split Array
// Accepted-unoptimized

class P2270 {
    public static int waysToSplitArray(int[] nums) {
        int ways=0;
        long psum[] = prefixSum(nums);
        for(int i=0;i<nums.length-1;i++){
            if(psum[i]>=psum[nums.length-1]-psum[i])
            ways++;
        }
        return ways;
    }
    public static long[] prefixSum(int[] nums){
        long psum[]=new long[nums.length];
        psum[0]=nums[0];
        for(int i=1;i<psum.length;i++){
            psum[i]=psum[i-1]+(long)nums[i];
        }
        return psum;
    }

}
/* another method is using prefix sum array. */

