class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> mpp=new HashMap<>();


        for(int i:nums){
            if(mpp.containsKey(i)){
                mpp.put(i,mpp.get(i)+1);
            }else{
                mpp.put(i,1);
            }
        }



        
        for(int key:mpp.keySet()){
            if(mpp.get(key)==1){
                return key;
            }
        }

        return -1;
    }
}