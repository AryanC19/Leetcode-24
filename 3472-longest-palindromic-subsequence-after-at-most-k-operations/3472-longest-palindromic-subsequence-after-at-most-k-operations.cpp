class Solution {
public:
    int dp[201][201][201];

    int func(int i,int j,string &s, int k){
        
        if(i==j) return 1;

        if(j<i) return 0;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int o1=func(i+1,j,s,k);
        int o2=func(i,j-1,s,k);

        int o3=0;
        int ops=min(abs(s[i]-s[j]), 26- abs(s[i]-s[j]));
        if(ops<=k){
            o3=2+func(i+1,j-1,s,k-ops);
        }

        return dp[i][j][k]= max({o1,o2,o3});
        

    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        int i=0;
        int j=n-1;
        memset(dp,-1,sizeof(dp));
        return func(i,j,s,k);

    }
};