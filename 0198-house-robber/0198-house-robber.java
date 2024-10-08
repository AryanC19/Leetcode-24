class Solution {
    int[] dp;

    public int func(int i, int[] nums) {
        if (i >= nums.length) return 0; 
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + func(i + 2, nums);  
        int nottake = func(i + 1, nums); 
        return dp[i]=Math.max(take, nottake);  
    }

    public int rob(int[] nums) {

        dp=new int[101];
        Arrays.fill(dp,-1);
        return func(0, nums);  
    }
}
