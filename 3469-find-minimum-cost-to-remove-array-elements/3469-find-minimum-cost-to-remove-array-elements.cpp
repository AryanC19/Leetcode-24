class Solution {
public:
    vector<vector<int> > dp;
    int n;
    int func(int pIdx,int idx,vector<int> &nums){

        if(idx>=n)  return nums[pIdx];
        
        if(idx==n-1) return max(nums[pIdx],nums[n-1]);

        if(dp[pIdx][idx]!=-1) return dp[pIdx][idx];

        int op1=max(nums[pIdx],nums[idx]) +func(idx+1,idx+2,nums);
        int op2=max(nums[pIdx],nums[idx+1]) + func(idx,idx+2,nums);
        int op3=max(nums[idx],nums[idx+1]) +func(pIdx,idx+2,nums);

        return dp[pIdx][idx]=min({op1,op2,op3});
    }
    int minCost(vector<int>& nums) {
        n=nums.size();
        dp.assign( n+1,vector<int> (n+1,-1));

        return func(0,1,nums);
    }
};