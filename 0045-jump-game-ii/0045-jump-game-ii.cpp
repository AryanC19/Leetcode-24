class Solution {
public:
    int res=1e9;
    int n;
    int dp[1001];
    int func(int i,vector<int> &nums){

        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int tot=1e9;
        for(int a=1;a<=nums[i];a++){
            tot=min(tot,1+func(i+a,nums));
            
        }
        return dp[i]=tot;
    }
    int jump(vector<int>& nums) {

        n=nums.size();
        memset(dp,-1,sizeof(dp));

        return func(0,nums);
        
    }
};