class P2661 {
        public int longestMonotonicSubarray(int[] nums) {
            int max_len_inc=0,max_len_dec=0,len=0,prevlen=0;
            for(int i=0;i<nums.length;i++){
                max_len_inc=maxlensubarray(nums,i,0);
                max_len_dec=maxlensubarray(nums,i,1);
                len=Math.max(max_len_inc,max_len_dec);
                prevlen=Math.max(prevlen,len);
            }
            return prevlen;
        }
        private int maxlensubarray(int nums[],int curr,int dir){
            int length=1;
            boolean flag=true;
            if(dir==0)
            for(int i=curr+1;i<nums.length;i++){
                if(nums[i]>nums[curr] && flag){
                    length++;
                    curr=i;
                    flag=true;
                }
                else
                flag=false;
            }
            else
            for(int i=curr+1;i<nums.length;i++){
                if(nums[i]<nums[curr] && flag){
                    length++;
                    curr=i;
                    flag=true;
                }
                else
                flag=false;
            }
            return length;
        }
    
    public static void main(String[] args) {
        int nums[]={1,4,3,3,2};
        P2661 p=new P2661();
        System.out.println(p.longestMonotonicSubarray(nums));   
    }
}
