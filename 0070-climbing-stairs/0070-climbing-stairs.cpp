class Solution {
public:
    
    int n;
    int dp[10001];

    int func(int i){

        if(i>=n) return 1;

        
        if(dp[i]!=-1) return dp[i];
        
        int tot=0;
        for(int a=1;a<=2;a++){
            tot+=func(i+a);
        }
        return dp[i]=tot;
    }

    int climbStairs(int N) {
        n=N;
        memset(dp,-1,sizeof(dp));
        return func(1);      

    }
};

