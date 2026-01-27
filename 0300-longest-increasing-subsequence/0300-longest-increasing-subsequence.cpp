class Solution {
public:

    int n;
    int dp[2501][2501];

    int func(int i,vector<int>& nums,int li){

        if(i>=n) return 0;
        if(li!=-1 && dp[i][li]!=-1) return dp[i][li];

        int nottake=func(i+1,nums,li);
        int take=0;
        if(li==-1 || nums[i]>nums[li]){
            take=1+func(i+1,nums,i);
        }
        if(li!=-1) 
           return dp[i][li]=max(take,nottake);
        return max(take,nottake);

    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return func(0,nums,-1);
    }
};