class Solution {
public:
    int func(int i, vector<int>& coins, int amount,vector<vector<int> > &dp){
        if(i<0 || amount<0) return 1e5;
        if(amount==0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int nt=func(i-1, coins, amount,dp);
        
        int t=1+func(i, coins, amount-coins[i],dp);
        return dp[i][amount]=min(t, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int> > dp ( n+1, vector<int> (amount+1, -1));
        int ans=func(n-1,coins, amount,dp);
        return ans==1e5?-1:ans;
    }
};