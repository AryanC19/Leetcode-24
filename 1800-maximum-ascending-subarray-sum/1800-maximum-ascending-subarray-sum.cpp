class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        


        int i=0;
        int n=nums.size();

        int sum=0;
        int ans=0;

        while(i<n){
            sum+=nums[i];
            if(i>0 && nums[i-1]>=nums[i]) sum=nums[i];
            ans=max(ans,sum);
            i++;        
        }
        return ans;
    }
};