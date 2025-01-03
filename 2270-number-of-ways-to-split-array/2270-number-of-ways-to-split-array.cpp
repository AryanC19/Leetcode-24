class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, long long> leftSum, rightSum;
        long long lsum = 0, rsum = 0;

        for (int i = 0; i < n; i++) {
            lsum += nums[i];
            leftSum[i] = lsum;
        }

        for (int i = n - 1; i >= 0; i--) {
            rsum += nums[i];
            rightSum[i] = rsum;
        }

        int splits = 0;
        for (int i = 0; i < n - 1; i++) { 
            if (leftSum[i] >= rightSum[i + 1]) {
                splits++;
            }
        }

        return splits;
    }
};
