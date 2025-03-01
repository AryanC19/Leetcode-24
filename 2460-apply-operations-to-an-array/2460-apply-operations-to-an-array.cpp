class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt0++;
            if(i+1==n) continue;
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        vector<int> ans;
        for(auto &i:nums){
            if(i!=0) ans.push_back(i);
        }
        while(cnt0--){
            ans.push_back(0);
        }

        return ans;

    }
};