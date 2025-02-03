class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        


        int len=1;
        int ans=1;
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]) len=0;
            else len++;
            ans=max(ans,len);
        }
        len=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<=nums[i]) len=0;
            else len++;
            ans=max(ans,len);
        }

        len=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]) len=0;
            else len++;
            ans=max(ans,len);
        }
        len=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) len=0;
            else len++;
            ans=max(ans,len);
        }
        return ans;
    }
};