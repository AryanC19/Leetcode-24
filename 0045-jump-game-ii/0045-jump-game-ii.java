class Solution {

    public int func(int i,int[] nums,int [] dp,int n){

        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        int minJumps=n;
        for(int a=1;a<=nums[i];a++){
            minJumps=Math.min(minJumps,1+func(i+a,nums,dp,n));
        }
        return dp[i]=minJumps;
    }
    public int jump(int[] nums) {
        
        int n=nums.length;

        int [] dp= new int[n];
        Arrays.fill(dp,-1);

        return func(0,nums,dp,n);
    }
}