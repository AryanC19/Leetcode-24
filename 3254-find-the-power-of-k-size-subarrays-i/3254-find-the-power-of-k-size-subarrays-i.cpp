class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         
        int n=nums.size();
        deque<int> dq;
        int r=0;
        vector<int> ans(n-k+1,-1);
        while(r<n){
            if(!dq.empty() && nums[r]!= dq.back ()+1) dq.clear();
            dq.push_back(nums[r]);
            if(dq.size()>=k){
                ans[r-k+1]=dq.back();
                dq.pop_front();
            }
            r++;
        }
        return ans;
    }
};