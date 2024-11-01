class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int func(int i, vector<int>& nums,int last_ind){
        if(i>=n) return 0;
        if(dp[i][last_ind+1]!=-1) return dp[i][last_ind+1];
        int nottake=func(i+1,nums,last_ind);
        int take=0;
        if(last_ind==-1 || nums[last_ind]<nums[i]){
            take=1+func(i+1,nums,i);
        }
        
        return dp[i][last_ind+1]=max(take,nottake);
        
    }
    int lengthOfLIS(vector<int>& nums) {    
        n=nums.size() ;
        dp.resize(n,vector<int> (n+1,-1));
        return func(0,nums,-1);       
    }
};