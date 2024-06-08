//50. Pow(x, n)
class P50{
    public static double myPow(double x, int n){
        if(n<0){
            x=x/(x*x);n*=-1;}
        if(x==0)
        {
        if(n>0)
        return 0.0;
        }
        if(n==0)
        return 1.0;
        double cal=myPow(x, n/2);
        if(n%2==1)
        return x*cal*cal;
        else {
            
        return cal*cal;}
}
public static void main(String[] args){
    int n=-2147483647;double x=2.0d;
    System.out.println("Answer: "+myPow(x,n));
}
}