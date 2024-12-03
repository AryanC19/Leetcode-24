class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        
        int n=nums.size();
        int l=0,r=1;
        set<int> sums;


        while(r<n){
            if(sums.count(nums[l]+nums[r])) return true;
            sums.insert(nums[l]+nums[r]);
            l++;
            r++;
        }
        return false;
    }
};