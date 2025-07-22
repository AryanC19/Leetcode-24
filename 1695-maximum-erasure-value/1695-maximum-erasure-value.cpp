class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();

        int l=0, r=0;

        unordered_map<int, int> lastOcc, presum;

        presum[0]=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            presum[i+1]=sum;    
        }
        int ans=0;
        while(r<n){
            if(lastOcc.count(nums[r])){
                l=max(l, lastOcc[nums[r]]+1);
            }
            ans=max(ans, presum[r+1]-presum[l]);
            lastOcc[nums[r]]=r;
            r++;
        }
        return ans;
    }
};
