class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // sum, count of 
        unordered_map<int,int> mpp;


        int n=nums.size();
        mpp[0]=1;
        int presum=0;
        int ans=0;
        for(auto i:nums){
            presum+=i;
            ans+=mpp[presum-k];
            mpp[presum]++;
        }

        return ans;
    }
};