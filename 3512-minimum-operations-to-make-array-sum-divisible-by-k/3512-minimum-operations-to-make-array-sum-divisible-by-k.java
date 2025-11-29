class Solution {
    public int minOperations(int[] nums, int k) {
        int sum=0;
        for(int i:nums) sum+=i;
        //System.out.println(sum);
        return sum%k;   
    }
}