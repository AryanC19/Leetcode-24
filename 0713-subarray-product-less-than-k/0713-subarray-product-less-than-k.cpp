class Solution {
public:
    //2025 p3
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();

        //mik vid think about later edge case
        if(k<=1) return 0;

        int cnt=0;
        int prod=1;

        int l=0,r=0;

        while(r<n){
            prod*=nums[r];
            // since req strictly less than , use >=
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            // to calculate the number of subarrays between j &i , use j-i+1
            cnt+= r-l+1;
            r++;
        }

        return cnt;
    }
};