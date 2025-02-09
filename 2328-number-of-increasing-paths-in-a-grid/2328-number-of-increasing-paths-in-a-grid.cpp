class Solution {
public:
    const int MOD=1e9+7;

    int ans=0;
    int m,n;
    void func(int i,int j,vector<vector<int>> &grid){

        if(i>=m || j>=n) return;

        const vector<vector<int> > dirs={{0,1},{1,0},{-1,0},{0,-1}};

        for(auto &dir:dirs){
            int ni=dir[0]+i;
            int nj=dir[1]+j;
            if(ni<m && nj<n && ni>=0 && nj>=0 && grid[i][j] < grid[ni][nj]){
                func(ni,nj,grid);
                ans=(ans+1)%MOD;
            }
        }
    }
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                func(i,j,grid);
            }
        }
        


        return (ans+ m*n)%MOD;




    }
};