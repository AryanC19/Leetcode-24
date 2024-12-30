class Solution {
public:
    const int MOD=1e9+7;
    int L,H;
    int Z,O;    
    
    int dp[100001];

    int func(int n){


        if(n>H) return 0;
        if(dp[n]!=-1) return dp[n];
        bool addToans=false;
        if(n>=L && n<=H) addToans=true;


        int addZero=func(n+Z);
        int addOne=func(n+O);

        return dp[n]=(addZero+addOne+ addToans)%MOD;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {

        memset(dp,-1,sizeof(dp));

        L=low,H=high,O=one,Z=zero;
        return func(0);   
    }
};