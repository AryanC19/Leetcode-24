class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=*max_element(begin(nums),end(nums));
        int mini=*min_element(begin(nums),end(nums));
        int n=nums.size();
        if(n==1) return 1;
        int l=0,r=n-1;
        int maxI,minI;
            

        for(int i=0;i<n;i++){
            if(nums[i]==maxi) maxI=i;
            if(nums[i]==mini) minI=i;
        }

        int leftLen=min(maxI,n-maxI+1);
        int rightLen=min(minI,n-minI+1);

        return leftLen+rightLen;
    }
};