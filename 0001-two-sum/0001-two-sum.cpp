class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        //            sum,ind
        unordered_map<int,int>  mpp;

        for(int i=0;i<n;i++){
           
            int rem=target-nums[i];
            if(mpp.count(rem)){
                return {i,mpp[rem]};
            }
            mpp[nums[i]]=i;
        }

        return {};
    }
};