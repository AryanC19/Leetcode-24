class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l=0;
        int r=0;
        int n=nums.size();
        int minDiff=INT_MAX;
        while(r<n){
            if(r-l+1>=k){
                int mini=nums[l];
                int maxi=nums[r];
                minDiff=min(minDiff, maxi-mini);
                l++;
            }
            r++;
        }
        return minDiff==INT_MAX? 0:minDiff;
    }
};