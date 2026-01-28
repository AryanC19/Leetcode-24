class Solution {
public:
    int m,n;
    
    int minPathFunc(int i,int j, vector<vector<int>>& grid,vector<vector<int>> &dp){

        if(i>=m || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=minPathFunc(i+1,j,grid,dp);
        int right=minPathFunc(i,j+1,grid,dp);
        return dp[i][j] = grid[i][j]+min(down,right);

    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return minPathFunc(0,0,grid,dp);
    }
};