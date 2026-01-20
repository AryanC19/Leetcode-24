class Solution {
    // tc O n, sc O 1
    public void rotate(int[][] mat) {
        int n=mat.length;
        int m=n;

        //first Transposing accross right diag
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // imp derivatino from drawing diagram
                int ni=n-1-j;
                int nj=n-1-i;

                int temp=mat[i][j];
                mat[i][j]=mat[ni][nj];
                mat[ni][nj]=temp;
            }
            m--;
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         System.out.print(mat[i][j]+" ");
        //     }
        //     System.out.println();
        // }

        //now reversing rows order
        int l=0,r=mat.length-1;
        while(l<r){
            int[] temp=mat[l];
            mat[l]=mat[r];
            mat[r]=temp;
            l++;r--;
        }
    }
}