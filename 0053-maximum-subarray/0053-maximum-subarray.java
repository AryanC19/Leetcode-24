class Solution {
    public int maxSubArray(int[] nums) {
        
        int sum=0;
        int maxSum=Integer.MIN_VALUE;

        int start=-1;
        int end=-1;
        int ansStart=-1;


        for(int i=0;i<nums.length;i++){
            
            if(sum==0){
                start=i;
            }
            sum+=nums[i];
            if(maxSum<=sum){
                maxSum=sum;
                end=i;
                ansStart=start;
            }
            if(sum<0){
                sum=0;
            }
        }

        //System.out.println(ansStart+","+end);
        for(int i=ansStart;i<=end;i++) System.out.print(nums[i]+" ");
        return maxSum;

    }
}