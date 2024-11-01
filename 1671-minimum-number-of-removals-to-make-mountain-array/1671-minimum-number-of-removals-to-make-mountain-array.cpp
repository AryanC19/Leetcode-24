class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        

        int n=nums.size();

        vector<int> lis(n,1),lds(n,1);
        //calc lis tabulation
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    lis[i]=max(lis[i],lis[prev]+1);
                }
            }
        }

        //calc lds tabulation
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i]){
                    lds[i]=max(lds[i],lds[prev]+1);
                }
            }
        }

        // get the no of removals by removig the lis/lds len from the total length (len-lis)
        //compute the min removals and return
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int removal= (i+1 -lis[i])+(n-i-lds[i]);
            ans=min(ans,removal);
        }
        return ans;
    }
};