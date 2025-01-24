package CodeFs;
import java.util.Scanner;

 class CFS1{
    public static int soln(int stamps,int stampsize,int steps[][]){
        int perimeter=0;
        int per_common_squares=0;
        int init_diagonal_coord_x=steps[0][0];
        int init_diagonal_coord_y=steps[0][1];
        int end_diagonal_coord_x=init_diagonal_coord_x+stampsize;
        int end_diagonal_coord_y=init_diagonal_coord_y+stampsize;
        for(int i=1;i<steps.length;i++){
            init_diagonal_coord_x=init_diagonal_coord_x+steps[i][0];
            init_diagonal_coord_y=init_diagonal_coord_y+steps[i][1];
            per_common_squares=per_common_squares+2*(Math.max(end_diagonal_coord_x-init_diagonal_coord_x,end_diagonal_coord_y-init_diagonal_coord_y)+1);
            end_diagonal_coord_x=init_diagonal_coord_x+stampsize;
            end_diagonal_coord_y=init_diagonal_coord_y+stampsize;
        }
        perimeter=4*stampsize*stamps-per_common_squares;
        return perimeter;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int testcases=sc.nextInt();
        while(testcases!=0){
        int stamps=sc.nextInt();
        int stampsize=sc.nextInt();
        int steps[][]=new int[stamps][2];
        for(int i=0;i<stamps;i++){
            for(int j=0;j<1;j++){
                System.out.println("Row-"+i);
                steps[i][j]=sc.nextInt();
            }
        }
        System.out.println(soln(stamps, stampsize, steps));               

    }
    testcases--;
    sc.close();
    }
}