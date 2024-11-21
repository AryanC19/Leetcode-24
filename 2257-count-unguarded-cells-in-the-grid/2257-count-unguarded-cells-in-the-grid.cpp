class Solution {
public:
    int m,n;
    void dfs(int i,int j,vector<vector<char>>& mat, char dir){

        if(i<0 || j<0 || i>=m || j>=n || mat[i][j]=='w' || mat[i][j]=='g'){
            return;
        }
        
        if(mat[i][j]=='.') mat[i][j]='m';

        if(dir=='l') dfs(i,j-1,mat,'l');
        if(dir=='r') dfs(i,j+1,mat,'r');
        if(dir=='d') dfs(i+1,j,mat,'d');
        if(dir=='u') dfs(i-1,j,mat,'u');

    }
    int countUnguarded(int M, int N, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        m=M;
        n=N;

        vector<vector<char >> mat(m,vector<char>(n,'.') );


        for(auto i:guards){
            int a=i[0];
            int b=i[1];
            mat[a][b]='g';
        }
        for(auto i:walls){
            int a=i[0];
            int b=i[1];
            mat[a][b]='w';
        }



       for(auto it: guards)
        {
            int i = it[0];
            int j = it[1];

            dfs(i-1,j,mat,'u');
            dfs(i,j+1,mat,'r');
            dfs(i,j-1,mat,'l');
            dfs(i+1,j,mat,'d');

        }
        int ans=0;
        
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                cout<<mat[i][j]<<" ";
                if(mat[i][j]=='.'){
                    ans++;

                }
            }
            cout<<endl;
        }
        return ans;

    }
};