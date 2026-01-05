class Solution {
    public long maxMatrixSum(int[][] mat) {
        
        int negCount=0;
        long smallestAbsVal = Integer.MAX_VALUE;
        long absSum=0;

        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j]<0){
                    negCount++;
                }
                smallestAbsVal=Math.min(smallestAbsVal, Math.abs(mat[i][j]));
                absSum+=Math.abs(mat[i][j]);
            }
        }
        System.out.println(smallestAbsVal);
        System.out.println(absSum);
        if(negCount%2==0) return absSum;
        else return absSum-2*smallestAbsVal;
    }
}