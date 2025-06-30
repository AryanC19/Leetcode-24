class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer ,Integer> freqMap=new HashMap<>();


        for(int i:nums){
            freqMap.put(i, freqMap.getOrDefault(i,0)+1);
        }
        int ans=0;

        for(int num: freqMap.keySet()){

            if(freqMap.containsKey(num+1)){
                int curr=freqMap.get(num)+freqMap.get(num+1);
                ans=Math.max(ans, curr);
            }
        }
        return ans;
    }
}