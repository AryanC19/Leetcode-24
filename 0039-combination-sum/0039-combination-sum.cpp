class Solution {
public:
    int n;
    void func(int ind, int k, vector<vector<int>>& ans, vector<int>& nums,
              vector<int>& ds) {
        // if sum<0 return since not possible
        if (k < 0)
            return;
        // base case, traversed all elements, and thencheck for sum condintion
        if (ind >= n) {
            if (k == 0) {
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(nums[ind]);
        // sending i instead fo i+1 to allow selection of elements more than once
        func(ind, k - nums[ind], ans, nums, ds);
        ds.pop_back();

        func(ind + 1, k, ans, nums, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        n = nums.size();
        func(0, k, ans, nums, ds);
        return ans;
    }
};