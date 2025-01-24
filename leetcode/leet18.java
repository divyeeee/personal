// 1930. Unique Length-3 Palindromic Subsequences
// Unaccepted - unoptimized

class P1930{
    public static int countPalindromicSubsequence(String s) {
        int palnum=0;
        int size=s.length();
        // Approach 1- unoptimized,-exceeded the time limit
        String superprocessed="";
        
        for(int i=0;i<size;i++){
            char let_i=s.charAt(i);
            if(superprocessed.indexOf(let_i)==-1 && s.lastIndexOf(let_i)!=i){
                // Now we need to count the number of unique characters in these indices.
                String processed="";
            for(int j=i+1;j<s.lastIndexOf(let_i);j++){
                char let_j=s.charAt(j);
                if(processed.indexOf(let_j)==-1){
                    palnum++;
                    processed=processed+""+let_j;
                }
            }
            }
            superprocessed=superprocessed+""+let_i;
        }
        // Approach 2- 
        return palnum;
    }
    public static void main(String[] args) {
        String trial="aabca";
        int res=countPalindromicSubsequence(trial);
        System.out.println(res);
    }

}
