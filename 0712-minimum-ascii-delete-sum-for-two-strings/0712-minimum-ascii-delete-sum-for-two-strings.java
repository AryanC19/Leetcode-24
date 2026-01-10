class Solution {
    // int minSum=Integer.MAX_VALUE;
    int dp[][];
    int getMinSum(int i , int j, String s1, String s2, int n, int m){
        if(i>=n){
            int s2Sum=0;
            for(int idx=j;idx<m;idx++){
                s2Sum+= (int) s2.charAt(idx);
            }
            return s2Sum;
        }
        if(j>=m){
            int s1Sum=0;
            for(int idx=i;idx<n;idx++){
                s1Sum+= (int) s1.charAt(idx);
            }
            return s1Sum;
        }

        if(dp[i][j]!=-1) return dp[i][j]; 
        char c1=s1.charAt(i);
        char c2=s2.charAt(j);

        if(c1==c2) return getMinSum(i+1,j+1,s1, s2, n, m);

        int deleteC2=(int)c2 +getMinSum(i,j+1,s1, s2, n, m);
        int deleteC1=(int)c1 +getMinSum(i+1,j,s1, s2, n, m);

        return dp[i][j]=Math.min(deleteC1,deleteC2);

    }
    public int minimumDeleteSum(String s1, String s2) {
        int n=s1.length();
        int m=s2.length();
        dp= new int[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        return getMinSum(0,0,s1,s2,n,m);        
    }
}