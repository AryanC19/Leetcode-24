class Solution {
public:

    int func(vector<int>& nums){
        int n=nums.size();

        vector<int > dp(n,1);
        int LIS=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    LIS=max(LIS,dp[i]);
                }
            }
        }
        return LIS;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();

        return func(nums);

    }
};