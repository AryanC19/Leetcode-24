class Solution {
public:
    typedef pair<int,int> P;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        priority_queue<P,vector<P>,greater<P>> pq;
        unordered_map<int,int> mpp;
        for(auto i:arr) mpp[i]++;

        for(auto i:mpp){
            pq.push({i.second,i.first});
        }
        /*
        1:5
        1:4
        */

        while(!pq.empty() && k --){
            auto p=pq.top();
            pq.pop();
            cout<<p.first<<" "<<p.second<<endl;
            p.first--;
            cout<<p.first<<" "<<p.second<<endl;
            if(p.first >0) pq.push(p);
        }

        // set<int> st;

        // while(!pq.empty()){
        //     st.insert(pq.top().second);
        //     pq.pop();
        // }

        return pq.size();

        
    }
};