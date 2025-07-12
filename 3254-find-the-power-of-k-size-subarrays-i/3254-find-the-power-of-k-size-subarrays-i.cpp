class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        // Handle k == 1 directly
        if (k == 1) {
            for (int i = 0; i < n; i++) ans[i] = nums[i];
            return ans;
        }

        int l = 0, r = 1;
        int consecPairs = 0;  // counts nums[i]–nums[i‑1]==1 in current window

        while (r < n) {
            // Add the new pair (r-1, r)
            if (nums[r] - nums[r - 1] == 1) consecPairs++;

            // When window [l..r] is size k
            if (r - l == k - 1) {
                // All k-1 pairs must be consecutive
                if (consecPairs == k - 1) {
                    ans[l] = nums[r];
                }
                // Remove the leftmost pair (l, l+1) before sliding
                if (nums[l + 1] - nums[l] == 1) consecPairs--;
                l++;
            }
            r++;
        }

        return ans;
    }
};
