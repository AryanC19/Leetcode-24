class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
    

        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }

        vector<int> ans;

        for (auto& i : queries) {

            auto lb=st.lower_bound(i[0]+1);
            auto ub=st.lower_bound(i[1]);

            st.erase(lb,ub);
            ans.push_back(st.size() - 1);
        }

        return ans;
    }
};