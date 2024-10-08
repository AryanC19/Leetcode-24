class Solution {



    public int subarraySum(int[] nums, int k) {
        

        HashMap<Integer,Integer> mpp=new HashMap<>();


        int presum=0;
        int ans=0;
        mpp.put(0, 1);

        for(int i:nums){

            presum+=i;
            int rem=presum-k;
            if(mpp.containsKey(rem)){
                ans+=mpp.get(rem);
            }
            
            mpp.put(presum, mpp.getOrDefault(presum, 0) + 1);
        }

        return ans;
    }
}