class Solution {
public:
    
    int maxWidthRamp(vector<int>& nums) {
        
        int n=nums.size();
        int ramp=0;

        for(int i=0;i<n;i++){
            int j=n-1;
            
            while(i<j && nums[j]<nums[i]){
                j--;
            }
            if(nums[j]>=nums[i])
                ramp=max(ramp,j-i);
        }
        return ramp;
    }
};