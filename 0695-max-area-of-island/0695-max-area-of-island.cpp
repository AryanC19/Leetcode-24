class Solution {
public:
    int ans=0;
    int m,n;
    const vector<pair<int,int> > dirs={{0,1},{1,0},{-1,0},{0,-1}};

    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>>& grid,int &count){
        
        vis[i][j]=1;
        for(auto &dir:dirs){
            int ni=i+dir.first;
            int nj=j+dir.second;
            if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj] && grid[ni][nj]==1){
                count=count+1;
                dfs(ni,nj,vis,grid,count);
            }
            ans=max(ans,count);
        }
    }   
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1 && !vis[i][j]){
                    int count=1;
                    dfs(i,j,vis,grid,count);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};