class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int func(int i,int j ,string &a, string &b){

        if(i>=n || j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return 1+func(i+1,j+1,a,b);
        }
        return dp[i][j]= max(func(i+1,j,a,b) ,func(i,j+1,a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        dp.resize(n,vector<int>(m,-1));
        return func(0,0,text1,text2);   
    }
};