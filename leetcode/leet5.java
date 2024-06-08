//59. Spiral Matrix II
class P59 {
    static int[][] matrix(int n)
    {
        boolean flag=true;
        int arr[][]=new int[n][n];
        int num=0,i=0,j=0,k=n;
        while(flag){
            //
            
            for(;j<n && flag;j++){
            arr[i][j]=++num;
            if(num>=k*k)
            flag=false;}
            //
            j--;
            i++;
            for(;i<n && flag;i++){
            arr[i][j]=++num;
            if(num>=k*k)
            flag=false;}
            //
            i--;
            j--;
            for(;j>=k-n && flag;j--){
            arr[i][j]=++num;if(num>=k*k)
            flag=false;}
            //
            j++;
            i--;
            for(;i>k-n && flag;i--){
            arr[i][j]=++num;if(num>=k*k)
            flag=false;}
            //
            i++;
            j++;
            n--;
        }
        return arr;

    }
    public static void main(String[] args) {
        int n=5;
        int arr[][]=new int[n][n];
        arr=matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}
