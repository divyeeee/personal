//69. Sqrt(x)
class P69
{
    public static long mySqrt(long x) {
        if(x==0)
            return 0;
        if(x==1)
            return 1;
         long low=1,high=x,mid=0;
         while(high-low!=1){
             mid=low+(high-low)/2;
             if(mid*mid==x)
                 return mid;
             if(mid*mid>x)
                 high=mid;
             else
                 low=mid;
         }
         return low;
     }
 public static void main(String args[]){
    System.out.println(mySqrt(2147395599));
 }
}