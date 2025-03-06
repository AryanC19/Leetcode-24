class Solution {
public:

    int n;
    int dp[301][5001];

    int func(int i,vector<int> &coins, int k){

        if(k==0)  return 1;
        if(k<0  || i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];

        int take= func(i,coins,k-coins[i]);
        int nottake=func(i+1,coins,k);
        
        return dp[i][k]=take+nottake;

    }
    int change(int k, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return func(0,coins,k);
    }
};