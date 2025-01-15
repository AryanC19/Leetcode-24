class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        
/*
36 59 71 15 26 82 87 
56 36 59 71 15 26 82 
15 0 36 59 71 15 26 
*/
        int n=mat.size();
        int m=mat[0].size();

        for(auto i:mat){

            for(auto j:i) cout<<j<<" ";
            cout<<endl; 
        }

        for(int j=0;j<m;j++){
            int i=0;
            int tj=j;
            int ele=mat[i][j];
            while(i<n && tj<m){
                if(mat[i++][tj++]!=ele) return false;
            }
        }
        for(int i=0;i<n;i++){
            int ti=i;
            int j=0;
            int ele=mat[i][j];
            while(ti<n && j<m){
                if(mat[ti++][j++]!=ele){
                    return false;
                }
            }
        }

        return true;
    }
};