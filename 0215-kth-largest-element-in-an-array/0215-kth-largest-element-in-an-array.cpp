class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();

        for(int i=0;i<k;i++) pq.push(nums[i]);

        int r=k;
        while(r<n){
            pq.push(nums[r]);
            if(pq.size()>k) pq.pop();
            r++;
        }

        return pq.top();
    }
};