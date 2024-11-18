import java.util.ArrayList;

class vid30{
    //subsequence of a string
    static void  subsequence(String p,String up){// p is the processesd string and up is the unprocessed string
        if(up.isEmpty()){
        System.out.println(p);
        return;}
        char fst=up.charAt(0);
        subsequence(p+fst,up.substring(1));
        subsequence(p,up.substring(1));
    }
    //storing in an array list
    static ArrayList<String>  subsequence1(String p,String up, ArrayList<String> lis){// p is the processesd string and up is the unprocessed string
        if(!(p.isEmpty() && up.isEmpty()))
        {
        if(up.isEmpty()){
        lis.add(p);
        return lis;}
        char fst=up.charAt(0);
        subsequence1(p+fst,up.substring(1),lis);
        subsequence1(p,up.substring(1),lis);}
        return lis;
    }
    //method 2 using array list, by distinction between left and right
    static ArrayList<String> subsequence2(String p, String up){
        if(up.isEmpty()){
            ArrayList<String> list=new ArrayList<String>(10);
            list.add(p);
            return list;
        }
        char fst=up.charAt(0);
        ArrayList<String> left= subsequence2(p+fst, up.substring(1));
        ArrayList<String> right= subsequence2(p, up.substring(1));
        left.addAll(right);
        return left;
    }
    public static void main(String[] args) {
        System.out.println("Testing the subsequences of a string");
        ArrayList<String> lis=new ArrayList<String>(10);
        System.out.println(subsequence2("","abc"));
    }
}
