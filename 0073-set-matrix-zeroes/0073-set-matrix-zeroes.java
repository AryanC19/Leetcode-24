class Solution {
    public void setZeroes(int[][] mat) {
        // OPTIMAL INPLACE
        int m=mat.length;
        int n=mat[0].length;

        // row_flag=mat[0][0] , so for col_flag we need another variable.
        int col_flag=1;

        //step1 mark both internal row and col based on 0's in matrix. 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(mat[i][j]==0){
                    if(j==0) col_flag=0;
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        //step2 now , based on internal row and col mapping, change 1-> 0 in all cells
        // EXCLUDING the internal row and col, ie the smaller matrix
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][0]==0) mat[i][j]=0;
                if(mat[0][j]==0) mat[i][j]=0;
            }
        }

        /*step3 now , we're left with the internal rows and cols mapping. 
         TRICKY: what to change 1st?
         every col -> col_flag , itself
         mat[0][0], mat[1][0], .....

         every row -> mat[i][j], itself
         col_flag, mat[0,1], mat[0,2], ....


         mat[0][0] changes all of ROWS mat[0][1],mat[0][2], mat[0][3] . . ..
         col_flag changes all of COLS mat[0][0], mat[1][0],mat[2][0] ....

         here we see that the ROWs are dependent on mat[0][0]
         the COLs are dependent on col_flag. 

         col_flag is an external variable. but mat[0][0] is a part of the matrix. if we change mat[0][0] 
         which is a part of the COLs, after that when we go to change the Rows, it will be wrong because we cahgnes the 
         depedant. 

         so first, we have to change the ROWs, ir mat[1][0], mat[2][0] ...
         then the COLs mat[0][0], mat[0][1] ...

         trick to remember : ALWAYS change the smaller array IR the one coupled with the var_flag first
         */



        for(int j=1;j<n;j++){
            if(mat[0][0]==0) mat[0][j]=0;
        }

        for(int i=0;i<m;i++){
            if(col_flag==0) mat[i][0]=0;
        }

    }
}