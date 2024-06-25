/*

 * * * *
 * * *
 * *
 * 
 
 */
//code for printing the above pattern using recursion
class vid29_Q1{
    public static void main(String args[]){
      pattern(0, 0);
    }
    static void pattern(int r,int c){
      if(r==4)
      return;
      if(c<=r){
        
        System.out.print(" *");
        pattern(r, c+1);
        
      }
      else{
        System.out.println();
        pattern(r+1, 0);
      }


    }
}