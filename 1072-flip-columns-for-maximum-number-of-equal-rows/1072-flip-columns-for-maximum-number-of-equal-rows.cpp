class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();

        int maxr=0;


        for(auto & curr:mat){
            vector<int> inverted;
            for(auto i:curr) inverted.push_back(!i);
            int cnt=0;

            for(auto &row :mat){

                if(row==curr || row==inverted){
                    cnt++;
                }
            }

            maxr=max(maxr,cnt);
        }

        return maxr;




    }
};