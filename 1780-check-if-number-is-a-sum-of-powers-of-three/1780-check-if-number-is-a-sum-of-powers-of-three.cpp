class Solution {
public:
    typedef long long ll;
    vector<int> dp;

    bool func(int i,ll sum){

        if(sum==0) return true;
        if(sum<0 || i>= 16) return false;
        int pows=pow(3,i);

        if(dp[sum]!=-1) return dp[sum];
        bool take=func(i+1, sum-pows);
        bool nottake=func(i+1, sum);
        return dp[sum]= take|nottake;
   }
    bool checkPowersOfThree(int n) {
        dp.assign(n+1,-1);
        return func(0,n);
    }
};