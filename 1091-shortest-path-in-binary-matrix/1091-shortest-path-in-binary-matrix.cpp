class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        dist[0][0]=0;
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        if(n==1 && n==1){
            if(grid[0][0]==0) return 1;
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int d=p.first;
            int r=p.second.first;
            int c=p.second.second;
            vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
            for(auto dir:dirs){
                int nr=r+dir.first;
                int nc=c+dir.second;
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                    if(d+1 <dist[nr][nc]){
                        if(nr==n-1 && nc==n-1){
                            dist[nr][nc]=d+2;
                            continue; 
                        }
                        dist[nr][nc]=d+1;
                        q.push({d+1,{nr,nc}});
                    }
                }
            }
        }

        return dist[n-1][n-1]==INT_MAX ?-1 :dist[n-1][n-1];
    }
};