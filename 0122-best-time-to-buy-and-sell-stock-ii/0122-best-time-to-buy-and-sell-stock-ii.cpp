class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int func(int i,vector<int>& arr, int canbuy){

        if(i>=n) return 0;

        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        int a=INT_MIN,b=INT_MIN;
        if(canbuy){
            int buy=func(i+1,arr,0)-arr[i];
            int notbuy=func(i+1,arr,1);
            a=max({a,buy,notbuy});
        }else{
            int sell=func(i+1,arr,1)+arr[i];
            int notsell=func(i+1,arr,0);
            b=max({b,sell,notsell});
        }
        return dp[i][canbuy]=max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.resize(n+1,vector<int> (2,-1));
        int canbuy=1;
        return func(0,prices,canbuy);   
    }
};