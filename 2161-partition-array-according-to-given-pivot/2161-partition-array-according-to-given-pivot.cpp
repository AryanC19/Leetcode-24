class Solution {
public:

    // O (1) space
    // O(N)
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int less=0,more=0,equal=0;

        for(auto i:nums){

            if(i<pivot) less++;
            else if(i>pivot) more++;
            else equal++;
        }
        vector<int> ans(n,0);

        int l=0,e=less,h=less+equal;
        for(auto i:nums){
            if(i<pivot) ans[l++]=i;
            else if(i>pivot) ans[h++]=i;
            else ans[e++]=i;
        }
        return ans;
    }
};