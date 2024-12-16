class Solution {
public:

    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        //min heap
        priority_queue<P,vector<P> ,greater<P>> pq;
        int n=nums.size();
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});

        while(k--){
            auto p=pq.top();
            pq.pop();
            int val=p.first *multiplier;
            int ind=p.second;
            pq.push({val,ind});
        }

        vector<int> ans(n);


        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int val=p.first;
            int ind=p.second;
            ans[ind]=val;
        }

        
        return ans;


    }
};