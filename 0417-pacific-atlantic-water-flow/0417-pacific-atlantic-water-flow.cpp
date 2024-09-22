class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        
        vector<vector<int>> vis1(n,vector<int> (m,0));
        vector<vector<int>> vis2(n,vector<int> (m,0));
        const vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};


        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){q.push({i,0}); vis1[i][0]=1;}
        for(int j=0;j<m;j++){q.push({0,j}); vis1[0][j]=1;}

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(auto &dir:dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx<n && ny<m && nx>=0 && ny>=0 && h[x][y] <= h[nx][ny] && !vis1[nx][ny]){
                    vis1[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        
        for(int i=0;i<n;i++){q.push({i,n-1}); vis2[i][n-1]=1;}
        for(int j=0;j<m;j++){q.push({m-1,j}); vis2[m-1][j]=1;}

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(auto &dir:dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx<n && ny<m && nx>=0 && ny>=0 && h[x][y] <= h[nx][ny] && !vis2[nx][ny]){
                    vis2[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};