class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        

        int zc=0,oc=0;

        int l=0,r=0;
        int n=nums.size();
        int ans=0;


        while(r<n){
            
            nums[r]==1 ? oc++:zc++;

            while(zc>k){
                nums[l]==0 ? zc--:oc--;
                l++;
            }

            if(zc<=k){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};