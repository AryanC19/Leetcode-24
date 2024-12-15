class Solution {
public:
    
    bool func(int i,vector<int>& nums, int target,int n,vector<vector<int>>&dp){

        if(target==0) return true;
        if(i>=n) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick=func(i+1,nums,target,n,dp);
        int pick=0;
        if(nums[i]<=target){
            pick=func(i+1,nums,target-nums[i],n,dp);
        }

        return  dp[i][target]=pick|notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        int target=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1)) ;
        if(sum%2!=0) return false;
        return func(0,nums,target,n,dp);

    }
};