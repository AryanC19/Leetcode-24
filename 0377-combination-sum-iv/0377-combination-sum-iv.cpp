class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int ind,vector<int>& arr, int target){
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=solve(i, arr, target - arr[i]);
        }
        return dp[ind][target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,target);
    }
};