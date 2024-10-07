class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        const vector<pair<int,int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        int strtime=0;
        vector<vector<int>> vis(n,vector<int> (m,0));

        queue<pair<int,pair<int,int>>> q;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==2){
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){

            auto p=q.front();
            q.pop();

            int time=p.first;
            ans=max(ans,time);
            int r=p.second.first;
            int c=p.second.second;


            for(auto dir:dirs){

                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nc>=0 && nr<n && nc< m && !vis[nr][nc] && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    vis[nr][nc]=1;
                    q.push({time+1,{nr,nc}});
                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};