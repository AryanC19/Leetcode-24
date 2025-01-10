class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // check first and last elements
        if(nums[0] != 0) return 0;
        if(nums[n-1] != n) return n;
        
        int l = 0, h = n-1;
        while(l <= h) {  
            int m = l + (h-l)/2;
            if(nums[m] != m) {  // If current value doesn't match index
                if(m > 0 && nums[m-1] == m-1) {  // Check if previous element is correct
                    return m;
                }
                h = m-1;
            } else {
                l = m+1;
            }
        }
        
        return n;  // Changed from -1 to n
    }
};