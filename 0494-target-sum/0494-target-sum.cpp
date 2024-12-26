class Solution {
public:
    int n;
    int dp[21][1001];
    int func(int i,vector<int>& nums, int target){

        if(i>=n && target==0) return 1;
        else if(i>=n) return 0;

        if(dp[i][target]!=-1) return dp[i][target];
        int nottake=func(i+1,nums,target);


        int take=0;

        if(target>=nums[i]){

            take=func(i+1,nums,target-nums[i]);
        }

        return dp[i][target]=take+nottake;

        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
        
        target=d;

        s1+s2=total
        s1=total-s2 --->1 

        s1-s2=d;  using 1

        totoal -s2-s2 =d
        total -2s2=d

        s2=( total-d) /2



       

        */
        n=nums.size();
        int total=0;


        memset(dp,-1,sizeof(dp));
        for(auto i:nums) total+=i;
        int s1= (-target+total)/2;
if (s1 < 0) return 0;
        // Check if target is achievable
        if (abs(target) > total) return 0;
        if ((target + total) % 2 != 0) return 0;

        return func(0,nums,s1); 
    }
};