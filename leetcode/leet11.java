//88. Merge Sorted Array
class P88
{
    public static void merge(int[] nums1, int m, int[] nums2, int n){
        if(nums1.length==0)
        nums1=nums2;
        else if(n==0)
        return;
        int p1=0,p2=0;
        for(int i=0;i<m+n;i++){
            if(i<m){
             if(nums1[p1]>nums2[p2])
              swap(nums1,nums2,p1,p2);
              sort(nums2,p2);
             p1++;}
            else{
             swap(nums1,nums2,p1,p2);
             p1++;
             p2++;}
      }
    }
    public static void sort(int arr[],int index){
        for(int i=index;i<arr.length-1;i++){
            if(arr[i]>arr[i+1])
            {
              swap(arr, arr, i+1, i);
            }
            else
            break;
        }
    }
    public static void  swap(int[] nums1,int[] nums2,int p1,int p2){
        int temp=nums1[p1];
        nums1[p1]=nums2[p2];
        nums2[p2]=temp;
        
    }
    public static void main(String[] args) {
        int[] nums1={4,5,6,0,0,0};
        int[] nums2={1,2,3};
        merge(nums1,nums1.length-nums2.length,nums2,nums2.length);
        for(int i=0;i<nums1.length;i++)
        System.out.println(nums1[i]);
    }
}