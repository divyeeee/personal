class Fibonacci{
    static long fiboformula(int n){
        return (long)((Math.pow((1+Math.sqrt(5))/2,n)-Math.pow((1-Math.sqrt(5))/2,n))/Math.sqrt(5));
    }
    public static void main(String args[]){
        System.out.println(fiboformula(99));
    }
}