class Solution {
public:
    int func(int i,vector<int>& arr,int n,int target,vector<vector<int> > &dp){
        if(target==0){
            return 1;
        }
        if(target<0 || i>=n) return 0;    

        if(dp[i][target] != -1) return dp[i][target];

        int take=0;
        // ***start a from 0 since diff seq counted and diff combinations
        for(int a=0;a<n;a++){
           /* since count ways, we init take outside, and += the func() call as 
            on base case it returns 1
        */ 
            take+=func(a,arr,n,target-arr[a],dp);
        }
        return dp[i][target]=take;
    }
    int combinationSum4(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int> > dp (n,vector<int> (target+1,-1));

        return func(0,arr,n,target,dp);
    }
};