class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {


        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>  res(n,vector<int> (m,-1));
        vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==0){

                    res[i][j]=0;
                    q.push({i,j});
                }

            }
        }

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();

            int r=p.first;
            int c=p.second;

            for(auto &dir:direction){
                int newr=r+dir[0];
                int newc=c+dir[1];

                if(newr>=0 && newc>=0 && newr<n &&newc<m && res[newr][newc]==-1){
                    res[newr][newc]=res[r][c]+1;
                    q.push({newr,newc});
                }
            }
        }

        return res;
    }
};