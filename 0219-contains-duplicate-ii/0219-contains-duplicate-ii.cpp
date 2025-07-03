class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_set<int> st;

        int l=0,r=0;
        
        while(r<n){
            
            if(st.count(nums[r])){
                if(r-l<=k) return true;
            }
            st.insert(nums[r]);

            if(r-l+1>k){
                st.erase(nums[l]);
                l++;
            }
            r++;
        }
        return false;
    }
};