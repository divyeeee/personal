// 2425. Bitwise XOR of All Pairings
// Accepted-Unoptimized
class P2425
{
    public static int xorAllNums(int[] nums1, int[] nums2) {
        int size1=nums1.length,size2=nums2.length;
        if(size1%2==0){
            if(size2%2==0){
                return 0;
            }
            else{
                return xored(nums1);
            }
        }
        else{
            if(size2%2==0){
                return xored(nums2);
            }
            else{
                return xored(nums1,nums2);
            }
        }
    }
    public static int xored(int nums[]){
        int xor=nums[0];
        for(int i=1;i<nums.length;i++){
            xor=xor^nums[i];
        }
        return xor;
    }
    public static int xored(int nums1[],int nums2[]){
        int xor=0;
        for(int i=0;i<nums1.length+nums2.length;i++){
            if(i<nums1.length)
            xor=xor^nums1[i];
            else
            xor=xor^nums2[i-nums2.length];
        }
        return xor;
    }
    public static void main(String[] args) {
        int nums1[]={2,1,3};
        int nums2[]={10,2,5,0};
        System.out.println(xorAllNums(nums1,nums2));
    }
}