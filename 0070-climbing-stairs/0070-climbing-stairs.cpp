class Solution {
public:
    vector<int> dp;
    int func(int n){
        if(n==0) return 1;
        if(n<0 ) return 0;

        if(dp[n]!=-1) return dp[n];
        int c1=func(n-1);
        int c2=func(n-2);

        return dp[n]= c1+c2;
    }
    int climbStairs(int n) {
       // this is if dp size known and init as int[]
       // memset(dp,-1,sizeof(dp));
       dp.resize(n+1,-1);
        return func(n);

    }
};