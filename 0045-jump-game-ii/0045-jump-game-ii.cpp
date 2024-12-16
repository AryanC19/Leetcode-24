class Solution {
public:

    /*
     i
     0 1 2 3 4
    [2,3,1,1,4]
    
    */

    int dp[10001];
    int func(int currInd,vector<int>& nums,int n){
        if(currInd>=n-1) return 0;
        if(dp[currInd]!=-1) return dp[currInd];
        int minJumps=n;
        for(int jumps=1;jumps<=nums[currInd];jumps++){
            minJumps=min(minJumps,1+func(currInd+jumps,nums,n));
        } 
        return dp[currInd]=minJumps;
    }
    int jump(vector<int>& nums) {

        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return func(0,nums,n);

    }
};