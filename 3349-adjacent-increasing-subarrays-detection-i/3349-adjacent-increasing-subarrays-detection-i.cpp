class Solution {
public:
    bool substrings(vector<int>& nums, int i, int k) {
        for (int j = i; j < i + k - 1; j++) {
            if (nums[j] >= nums[j + 1]) 
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) { 
            if (substrings(nums, i, k)) {
                if (substrings(nums, i + k, k)) {
                    return true;
                }
            }
        }
        return false;
    }
};