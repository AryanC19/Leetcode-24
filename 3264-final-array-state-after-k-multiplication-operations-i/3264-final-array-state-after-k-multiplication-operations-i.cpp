class Solution {
public:

    typedef pair<int,int> P;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        //min heap
        priority_queue<P,vector<P> ,greater<P>> pq;

        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});

        while(k--){
            auto p=pq.top();
            pq.pop();
            int val=p.first *multiplier;
            int ind=p.second;
            pq.push({val,ind});
        }

        vector<P> arr;

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int val=p.first;
            int ind=p.second;
            arr.push_back({ind,val});
        }

        sort(begin(arr),end(arr));

        vector<int> ans;

        for(auto i:arr){
            ans.push_back(i.second);
        }
        return ans;


    }
};