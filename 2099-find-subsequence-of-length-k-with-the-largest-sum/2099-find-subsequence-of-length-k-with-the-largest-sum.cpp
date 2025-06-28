class Solution {
public:
    typedef pair<int,int> P;
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<P,vector<P> , greater<P> > pq;
        // auto comp=[&](P a1, P a2){
        //     return a1.second<a2.second;
        // }
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
            if(pq.size()>k)pq.pop();
        }   
        set<int> st;
        while(!pq.empty()){
            st.insert(pq.top().second);
            pq.pop();
        }
        vector<int > ans;

        for(auto it=st.begin();it!=st.end();it++){
            ans.push_back(nums[*it]);
        }
        return ans;
    }
};