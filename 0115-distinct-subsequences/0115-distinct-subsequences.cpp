class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string s, string t){

        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i-1,j-1,s,t) + solve(i-1,j,s,t);
        }
        
        return dp[i][j]=solve(i-1,j,s,t);
        
    }
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int m=t.size();
        return solve(n-1,m-1,s,t);
    }
};