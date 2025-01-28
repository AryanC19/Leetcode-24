class Solution {
public:
    int maxFish=0;
    int m,n;
    void func(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &vis){
        
        if(i>=m || j>=n) return;
        vis[i][j]=1;
        const vector<pair<int,int> > dirs= {{0,1},{1,0},{-1,0},{0,-1}};

        int ans=grid[i][j];
        for(auto &dir:dirs){
            int ni=dir.first+i;
            int nj=dir.second+j;
            if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj] && grid[ni][nj]>0 ){
                ans+=grid[ni][nj];
                func(ni,nj,grid,vis);
            }
        }
        maxFish=max(maxFish,ans);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    func(i,j,grid,vis);
                }
            }
        }
        return maxFish;


    }
};