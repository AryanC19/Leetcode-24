class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> dp;
    int func(int i, vector<int>& arr, int k) {
        if (k < 0) return 0; 
        if (i == n) {
            return (k == 0) ? 1 : 0; 
        }
        
        if (dp[i][k] != -1) return dp[i][k];
        
        int nottake = func(i + 1, arr, k);
        
        int take = 0;
        if (arr[i] <= k) {
            take = func(i + 1, arr, k - arr[i]);
        }
        
        return dp[i][k] = (take + nottake)% MOD;
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        n = arr.size();
        int sum= accumulate(begin(arr),end(arr),0);

       //if (abs(target) > sum) return 0;
        if((sum-target)%2!=0) return 0;
        int k=(sum-target)/2;
        if(k < 0) return 0;  // Add this line before dp resize
        
        
        
        dp.resize(n+1, vector<int>(k + 1, -1)); 
        return func(0, arr, k);        
    }
};