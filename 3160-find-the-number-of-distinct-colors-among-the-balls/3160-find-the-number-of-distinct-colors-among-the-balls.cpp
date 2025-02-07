class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_set<int> st;
        unordered_map<int,int> mpp;


        int n=queries.size();

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int ball=queries[i][0];
            int color=queries[i][1];


            if(mpp.count(ball)){
                st.erase(mpp[ball]);
            }
            mpp[ball]=color;
            st.insert(color);

            ans[i]=st.size();

        }
        return ans;
    }
};