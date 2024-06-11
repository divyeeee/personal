//70. Climbing Stairs
class P70{
    public static int climbStairs(int n){
     int sum=0;
     for(int i=1;i<n;i++){
     int b=1;
     while(b<(i/2)+1){
        sum=sum+(factorial(i)/factorial(i-b));
        b++;
     }}
     return sum+1;
    }
    public static int factorial(int n){
        if(n==1 || n==0)
        return 1;
        else return n*factorial(n-1);
    }
    public static void main(String[] args){
        System.out.println("The number of different ways are: "+climbStairs(3));
    }
}