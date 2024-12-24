class Solution {
public:
   int n;
   int dp[1001][2];
   int func(int i,vector<int> &nums,bool positive){
       if(i>=n) return 0;
       if(dp[i][positive]!=-1) return dp[i][positive];
       int nottake=func(i+1,nums,positive);
       int take=0;
       if((nums[i]-nums[i-1]>0 && !positive) || (nums[i]-nums[i-1]<0 && positive)){
           take=1+func(i+1,nums,!positive);
       }
       return dp[i][positive]=max(take,nottake);
   }
   int wiggleMaxLength(vector<int>& nums) {
       n=nums.size();
       if(n<=1) return n;
       
 
       int i=1;
        memset(dp,-1,sizeof(dp));
       return max(func(1,nums,true), func(1,nums,false)) + 1;
   }
};