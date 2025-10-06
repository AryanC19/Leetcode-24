class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> indMap=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int rem=target-nums[i];
            if(indMap.containsKey(rem)){
                return new int[]{indMap.get(rem), i};
            }
            indMap.put(nums[i],i);
        }
        return null;
    }
}