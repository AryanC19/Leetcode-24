class Solution {
public:
    void func(vector<int> nums,vector<vector<int>>& ans, vector<int>& ds, vector<int>& freq) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {

            if (!freq[i]) {

                freq[i] = 1;
                ds.push_back(nums[i]);
                func(nums,ans,ds,freq);
                ds.pop_back();
                freq[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> freq(n, 0);
        func( nums,  ans,ds, freq);
        return ans;
    }
};