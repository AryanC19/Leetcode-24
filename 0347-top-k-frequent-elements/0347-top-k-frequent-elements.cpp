class Solution {
public:
typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P,vector<P>> pq;
        unordered_map<int,int> mpp;
        for(auto i:nums)mpp[i]++;

        for(auto i:mpp){
            pq.push({i.second,i.first});
        }

        vector<int> ans;
        while(k--){  
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;

    }
};