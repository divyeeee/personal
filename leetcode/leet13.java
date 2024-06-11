//409. Longest Palindrome
class P409 {
    //method only acceptible when our string has been arranged alphabetically
    public static int longestPalindrome(String s) {
        int max=0,len=0;
        for(int i=0;i<s.length();){
            String chr=""+s.charAt(i);
            int diff=s.lastIndexOf(chr)-i+1;
            if(diff%2==0){
            i+=diff;
            len+=diff;}
            else{
                if(diff>max)
                max=diff;
                i+=diff;
            }    
        }
        return len+max;
    }
    //using method to store the number of apperances of the character.
    public static int longestPalindrome2(String s){
        int arr[]=new int[52];char chr='a';
        for(int i=0;i<s.length();i++){
            chr=s.charAt(i);
            if(chr<96)
                arr[((int)chr)-39]++;
            else
                arr[((int)chr)-97]++;
        }
        int max=0,len=0;
        for(int i:arr){
            if(i==0)
            continue;
            if(i%2==0)
            len+=i;
            else
            {
                if(i>max)
                max=i;
            }
           
        }
        return max+len;
    }
    public static void main(String args[]){
        System.out.println(longestPalindrome2("\"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth..."));
    }
}