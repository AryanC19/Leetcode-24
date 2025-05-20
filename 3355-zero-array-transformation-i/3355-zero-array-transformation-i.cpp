class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diffArr(n + 1, 0);

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            diffArr[l]--;
            diffArr[r + 1]++;
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) diffArr[i] += diffArr[i - 1];
            if (nums[i] > abs(diffArr[i])) return false;
        }

        return true;
    }
};
