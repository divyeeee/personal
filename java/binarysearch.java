//program for binary search
public class binarysearch {
    static int binarySearch(int[] arr, int key) {
        int low = 0, high = arr.length - 1;int step=1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
                System.out.println("Number of steps is "+step);
                return mid;
            }
            if (arr[mid] < key) {
                low = mid + 1;
                step++;
            } else {
                high = mid - 1;
                step++;
            }
        }
        return -1;
    }
    static String binary2dSearch(int[][] arr,int row,int col, int key){
        int R=0,C=col-1;int step=1;
        while(R<row && C>=0){
            if(arr[R][C]==key)
            {
                System.out.println("Number of steps is "+step);
                System.out.println("Row = "+R+" Column = "+C+" for key = "+key);
                return ""+R+","+C;
            }
            else if(arr[R][C]<key)
            {
                R++;
                step++;
            }
            else{
                C--;
                step++;
            }
        }
        return "-1";
    }
}