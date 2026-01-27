class Solution {
public:
    int n;
    const vector<vector<int>> dirs= {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int i, int j, vector<vector<int>>& grid, set<pair<int,int>>& vis) {
    if (i < 0 || j < 0 || i >= n || j >= n ||
        grid[i][j] == 0 || vis.count({i,j})) {
        return;
    }

    vis.insert({i,j});

    for (auto &dir : dirs) {
        dfs(i + dir[0], j + dir[1], grid, vis);
    }
}

    int bfs(vector<vector<int>>& grid,set<pair<int,int >>  &vis){
        

        queue<pair<int,int> > q;
        for (auto &p : vis) {
            q.push(p);
        }


        int lvl=0;

        while(!q.empty()){

            int size=q.size();

            while(size--){

                auto p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                for(const vector<int> & dir: dirs){
                    int ni=i+dir[0];
                    int nj=j+dir[1];
                    if(ni>=0 && nj>=0 && ni<n && nj<n && !vis.count({ni,nj}) ){
                        if(grid[ni][nj]==1 ){
                            return lvl;
                        }
                        q.push({ni,nj});
                        vis.insert({ni,nj});
                    }
                }
            }
            lvl++;
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();

        set<pair<int,int >>  vis;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1 ){
                    dfs(i,j,grid,vis);
                    return bfs(grid,vis);
                }
            }
        }

        return -1;
        
    }
};