//118. Pascal's Triangle
import java.util.ArrayList;
class P118{
    public static ArrayList<ArrayList<Integer>> generate(int numRows){
        ArrayList<ArrayList<Integer>> list=new ArrayList<>(numRows);
        for(int i=0;i<numRows;i++){
            list.add(new ArrayList<>());
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i)
                list.get(i).add(1);
                else
                list.get(i).add(list.get(i-1).get(j-1)+list.get(i-1).get(j));
            }
        }
        return list;
    }
    public static void main(String args[]){
        System.out.print(generate(4));
    }
}