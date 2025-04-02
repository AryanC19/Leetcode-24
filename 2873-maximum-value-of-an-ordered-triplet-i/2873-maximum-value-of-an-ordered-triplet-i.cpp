class Solution {
public:

    typedef long long ll;
    int n;
    vector<vector<vector<ll> > > dp ;

    ll func(int i,int j ,int k, vector<int> &nums){

        if(i>=n || j>=n || k>=n) return LLONG_MIN ;

        if(dp[i][j][k] !=-1) return dp[i][j][k];


        ll triplet=((ll)nums[i] - (ll)nums[j]) * (ll)nums[k];


        ll f1= func(i+1,j+1,k+1,nums);
        ll f2=func(i,j+1,k+1,nums);
        ll f3=func(i,j,k+1,nums);

        return dp[i][j][k]=max({triplet,f1,f2,f3});
    }
    long long maximumTripletValue(vector<int>& nums) {
        n=nums.size();
        dp.resize( n,vector<vector<ll>> (n,vector<ll> (n,-1)));
        ll ans=func(0,1,2,nums);
        return ans>=0 ? ans : 0;
    }
};