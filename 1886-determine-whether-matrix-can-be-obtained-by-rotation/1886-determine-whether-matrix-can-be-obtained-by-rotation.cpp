class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(auto &i:mat) reverse(begin(i),end(i));
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& targ) {

        

        for(int i=0;i<4;i++){
            rotate(targ);
            if(mat==targ) return true;

        }
        return false;
    }
};