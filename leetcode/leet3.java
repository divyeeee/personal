//66. Plus One
class P66{
    static int[] digits(int[] digits)
    {
        int sum=digits[digits.length-1]+1;
        int carry=sum/10;
        digits[digits.length-1]=sum%10;
        for(int i=digits.length-2;i>=0;i--)
        {
            sum=digits[i]+carry;
            carry=sum/10;
            digits[i]=sum%10;
        }
        if(carry==0)
        return digits;
        else{
            int newarr[]=new int[digits.length+1];
            newarr[0]=1;
            for(int i=1;i<newarr.length;i++)
            {
                newarr[i]=digits[i-1];
            }
            return newarr;
        }
    }
  public static void main(String[] args)
  {
    int arr[]={9};
    arr=digits(arr);
    for(int i=0;i<arr.length;i++){
        System.out.println(arr[i]);
    }
  }
}