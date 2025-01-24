class Solution {
public: 
    int n;
    int dp[301][5001];
    int func(int idx,int sum, vector<int>& coins){
        
        if(idx>=n) return 0;
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take=func(idx,sum-coins[idx],coins);
        int nottake=func(idx+1,sum,coins);
        return dp[idx][sum]=take+nottake;
    }
    int change(int sum, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return func(0,sum,coins);
    }
};