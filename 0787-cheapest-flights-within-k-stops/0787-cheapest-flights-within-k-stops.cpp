class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<pair<int,int>> adj[n];

        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        queue<P> pq;
        //stops,node,dist
        pq.push({0,{src,0}});
        int ans=0;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!pq.empty()){

            auto p=pq.front();
            pq.pop();
            int stops=p.first;
            int node=p.second.first;
            int cost=p.second.second;

            if(stops>k){
               continue;
            }
            for(auto nodes:adj[node]){
                int adjNode=nodes.first;
                int wt=nodes.second;
                if(dist[adjNode]>cost+wt && stops<=k){
                    dist[adjNode]=cost+wt;
                    pq.push({stops+1,{adjNode,cost+wt}});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};