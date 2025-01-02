class Solution {
public:
    int n;
    int dp[1001];
    int func(int i,vector<int>& nums){

        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int minJumps=1e9;
        int jumps=0;
        for(int a=1;a<=nums[i];a++){
            jumps=1+func(i+a,nums);
            minJumps=min(minJumps,jumps);
        }
        
        return dp[i]=minJumps;

    }
    int jump(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,nums);
    }
};