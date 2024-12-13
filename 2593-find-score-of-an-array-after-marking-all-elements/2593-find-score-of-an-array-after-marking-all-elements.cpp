class Solution {
public:
    typedef pair<int,int> P;
    long long findScore(vector<int>& nums) {
        
        priority_queue<P,vector<P>,greater<P>> pq;
        long long scr=0;
        int n=nums.size();

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }


        while(!pq.empty()){
            auto p=pq.top();
            int ind=p.second;
            int val=p.first;

            if(!vis[ind]){
                vis[ind]=1;
                scr+=val;
                if(ind-1>=0) vis[ind-1]=1;
                if(ind+1 <n) vis[ind+1]=1;
            }else{
                pq.pop();
            }
        }
        return scr;
        
    }
};