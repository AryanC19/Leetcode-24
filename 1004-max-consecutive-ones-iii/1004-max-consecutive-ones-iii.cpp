class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        

        int n=nums.size();

        int l=0; 
        int r=0;
        int zeroCount=0;
        int maxLen=0;
        while(r<n){
            zeroCount+= nums[r]==0?1:0;
            //handling invalid condition
            while(zeroCount>k){
                zeroCount-= nums[l]==0? 1:0;
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};