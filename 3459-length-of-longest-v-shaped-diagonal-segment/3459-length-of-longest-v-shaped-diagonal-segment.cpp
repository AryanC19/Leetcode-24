class Solution {
public:

/*
from start 2 op either
1) if valid continue
2) if turn==0 then turn++;
*/
    int n, m;
    const vector<vector<int>> dirs={{-1,-1},{-1,1},{1,1},{1,-1}};

    int func(int i, int j , vector<vector<int>>& grid , int turn, int dir, int prev){
        
        if(i>=n || j>=m || i<0 || j<0 ) return 0;
        int curr=grid[i][j];
        if(!((prev==1 && curr==2) || 
            (prev==2 && curr==0) || 
            (prev==0 && curr==2))) return 0;
        
        
        int maketurn=0, dontturn=0;
        
        //either turn
        if(turn){
            int ni=i+dirs[(dir+1)%4][0];
            int nj=j+dirs[(dir+1)%4][1];

            if(ni<n && nj<m && ni>=0 && nj>=0 ){
                maketurn=1+func(ni,nj,grid,0,(dir+1)%4,curr);
            }
        }
        // or contnue if valid
        int ni=i+dirs[dir][0];
        int nj=j+dirs[dir][1];
        dontturn=1+func(ni,nj,grid,turn,dir,curr);

        return max(maketurn,dontturn);
        
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    for(int dir=0;dir<4;dir++){
                        int ni = i + dirs[dir][0];
                        int nj = j + dirs[dir][1];
                        ans = max(ans, 1 + func(ni, nj, grid, 1, dir, 1));
                    }
                }
            }
        }
        return ans;
    
    }
};