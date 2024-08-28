//2951. Find the Peaks

import java.util.ArrayList;

class P2951{
    public static ArrayList<Integer> findPeaks(int[] mountain) {
      ArrayList<Integer> lis=new ArrayList<Integer>(10);
      for(int i=1;i<mountain.length-1;i++){
        if(mountain[i]>mountain[i+1] && mountain[i]>mountain[i-1])
        lis.add(i);
      }
      return lis;
    }
   
   public static void main(String[] args) {
    int mountain[] = {1,4,3,8,5};
    System.out.println(findPeaks(mountain));
   }
}