class Solution {
public:
    int minSubarray(vector<int>& arr, int p) {
        int sum = 0;
        for (auto i : arr) sum = (sum + i) % p;  // Calculate the total sum % p
        
        int rem = sum % p;  // The remainder that we need to remove to make sum divisible by p
        if (rem == 0) return 0;  // No need to remove anything if the sum is already divisible by p
        
        unordered_map<int, int> mpp;
        int presum = 0;
        mpp[0] = -1;  // Base case for subarrays starting from index 0
        int n = arr.size();
        int len = INT_MAX;  // We need to minimize the length of the subarray
        
        for (int i = 0; i < n; i++) {
            //imp
            presum = (presum + arr[i]) % p;  // Update the prefix sum % p
            

            //imp
            int target = (presum - rem + p) % p;  // Calculate the target prefix sum
            
            if (mpp.find(target) != mpp.end()) {
                len = min(len, i - mpp[target]);  // Find the smallest subarray
            }
            
            mpp[presum] = i;  // Store the current prefix sum % p with its index
        }
        
        // If no valid subarray was found, return -1. Otherwise, return the minimum length.
        return len == INT_MAX || len == n ? -1 : len;
    }
};
