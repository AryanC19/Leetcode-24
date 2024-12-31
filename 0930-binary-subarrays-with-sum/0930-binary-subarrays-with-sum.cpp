class Solution {
public:
    // prob 2 2025
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        int sum=0;
        while(r<n){

            sum+=nums[r];

            while(l<r && sum>goal){
                sum-=nums[l];
                l++;
            }

            if(sum==goal){

                int tl=l;
                while(tl<r && nums[tl]==0){
                    ans++;
                    tl++;
                }

                ans++;
            }
            r++;
        }

        return ans;
    }
};