class Solution {
public:

    // int func(int r, int c,vector<vector<int>>& mat,vector<vector<int>>& dp){
    //     if(r>= mat.size() ||c<0 || c>=mat[0].size()){
    //         return 1e9;
    //     }
    //     if(r==mat.size()-1){
    //         return mat[r][c];
    //     }
    //     if(dp[r][c]!=-1) return dp[r][c];
    //     int leftd=mat[r][c]+ func(r+1,c-1,mat,dp);
    //     int down=mat[r][c]+ func(r+1,c,mat,dp);
    //     int rightd=mat[r][c]+ func(r+1,c+1,mat,dp);
    //     return dp[r][c]=min(down,min(leftd,rightd));
    // }
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));

        //bottom up tabulation        
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){

                if(r==0) dp[r][c]=mat[r][c];
                else{

                    int leftd=mat[r][c],rightd=mat[r][c],down=mat[r][c];

                    if(r>0 && c>0)
                        leftd+= dp[r-1][c-1];
                    else
                        leftd+=1e9;

                    if(r>0)
                        down+= dp[r-1][c];
                    else
                        down+=1e9;

                    if(r>0 &&c<n-1)
                        rightd+=dp[r-1][c+1];
                    else
                        rightd+=1e9;
                    
                    dp[r][c]=min(leftd,min(down,rightd));
                }

            }
        }
        
        int ans = INT_MAX;
        for (int c = 0; c < n; c++) {
            ans = min(ans, dp[m-1][c]);
        }

        return ans;
    }
};