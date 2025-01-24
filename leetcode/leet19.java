// 2381. Shifting Letters II

class P2381{
    public static String shiftingLetters(String s, int[][] shifts) {
        int size=s.length();
        int total_shift[]=new int[size];
        int asci[]=new int[size]; 
        for(int i=0;i<size;i++){
            asci[i]=(int)s.charAt(i)-97;
        }
        for(int i=0;i<shifts.length;i++){
            

        }
        return s;
    }
    public static void main(String[] args) {
        String s="abc";
        int shifts[][]={{0,1,0},{1,2,1},{0,2,1}};
        String res=shiftingLetters(s,shifts);
        System.out.println(res);
    }

    