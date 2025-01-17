class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int ps=0;
        int n=nums.size();

        unordered_map<int,int> mpp;
        int ans=0;
        mpp[0]=1;
        for(int &i:nums){
            ps+=i;
            int rem=ps-goal;
            if(mpp.count(rem)){
                ans+=mpp[rem];
            }
            mpp[ps]++;
        }
        return ans;
    }
};