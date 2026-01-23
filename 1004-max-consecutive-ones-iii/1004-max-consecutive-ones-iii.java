class Solution {
    public int longestOnes(int[] nums, int k) {
        int n=nums.length;

        int l=0;
        int r=0;

        int zero=0;
        int ans=0;

        while(r<n){
            zero += nums[r]==0 ? 1:0;
            while(zero>k){
                zero-= nums[l]==1?0 : 1;
                l++;
            }
            ans=Math.max(ans, r-l+1);
            r++;
        }

        return ans;
    }
}