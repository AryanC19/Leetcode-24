class Solution {
public:
    int n,m;
    bool isSafe(int r,int c){
        return r>=0 && c>=0 && r<n && c<m;
    }

    vector<vector<int>> dp;
    int totcnt=0;
    int func(int r,int c,vector<vector<int>>& grid){
        if(r>= n || c>=m){
            return totcnt;
        }
        if(dp[r][c] !=-1) return dp[r][c];
        
        int totcnt=0;
        const vector<pair<int,int>> dirs={{0,1},{-1,1},{1,1}};
        for(auto i:dirs){
            int nr=r+i.first;
            int nc=c+i.second;
            
            if(isSafe(nr,nc) && grid[r][c] < grid[nr][nc]){
                totcnt =max(totcnt,func(nr,nc,grid)+1);
            }
        }

        return dp[r][c]=totcnt;
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            ans=max(ans,func(i,0,grid));
        }
        return ans;
        

    }
};