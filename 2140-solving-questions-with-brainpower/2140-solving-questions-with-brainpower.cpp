class Solution {
public:

    typedef long long ll;
    int n;
    vector<ll> dp;

    ll func(int i,vector<vector<int>>& questions){

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        ll take=questions[i][0] + func(i+1+questions[i][1], questions);
        ll nottake=func(i+1, questions) ;
        return dp[i]= max(take,nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        dp.resize(n,-1);
        return func(0,questions);
    }
};