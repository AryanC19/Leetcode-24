class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        const vector<pair<int,int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};


        vector<vector<int> > vis(n,vector<int> (m,0));
        queue<pair<int,pair<int,int >>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int time=p.first;
            ans=max(ans,time);
            int i=p.second.first;
            int j=p.second.second;
            for(auto &dir:dirs){
                int ni=i +dir.first;
                int nj=j +dir.second;
                if(ni<n && nj<m && ni>=0 && nj>=0 && !vis[ni][nj] && grid[ni][nj] ==1){
                    vis[ni][nj]=1;
                    grid[ni][nj]=2;
                    q.push({time+1,{ni,nj}});
                }
            }
        }


        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
        
    }
};