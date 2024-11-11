class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;


        mpp[0]=-1;
        int ans=0;
        int ps=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            ps+= nums[i]==1?1:-1;

            if(mpp.count(ps)){
                ans=max(ans,i- mpp[ps]);
            }else{
                mpp[ps]=i;
            }
        }

        return ans;
    }
};