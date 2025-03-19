class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int mask = 0;
        int ans = 1;

        while (r < n) {
            while ((mask & nums[r]) != 0) { 
                mask ^= nums[l];
                l++;
            }

            mask |= nums[r];
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
