class Solution {
public:
    int n;
    vector<int> dp;
    int func(int i,vector<int>& nums){

        if(i>=n-1){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];
        int jump=n;
        for(int j=1;j<=nums[i];j++){
            jump=min(jump,1+func(i+j,nums)) ;           
        }
        return dp[i]=jump;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        return func(0,nums);

    }
};