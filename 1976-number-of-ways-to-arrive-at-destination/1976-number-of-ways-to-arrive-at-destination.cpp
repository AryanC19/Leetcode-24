class Solution {
public:
typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        


        unordered_map<int, vector< pair<int,int> >> adjList;


        for(auto &i:roads){

            int u=i[0];
            int v=i[1];
            int time=i[2];

            adjList[u].push_back({v,time});
            adjList[v].push_back({u,time});
        }

        //dist,node
        priority_queue<pair<ll,ll > ,vector<pair<ll,ll > > , greater<pair<ll,ll > > > pq;
        int MOD=1e9+7;

        pq.push({0,0});

        vector<ll> dist(n,1e12),ways(n,0);

        dist[0]=0;
        ways[0]=1;



        while(!pq.empty()){

            auto [wt,node]=pq.top();
            pq.pop();
            
            for(auto [adjNode,adjWt]: adjList[node]){
                

                //coming with the shortest dist for the first time
                if(dist[adjNode]>wt+adjWt){

                    dist[adjNode] =wt+adjWt;

                    pq.push({wt+adjWt,adjNode});

                    // set the ways of adjNode to ways of node since visiting first time
                    ways[adjNode]=ways[node];

                }else if( dist[adjNode]== wt+adjWt){
                    // if already shortest path present in dist, increase ways[adjNde]
                    //with the numways to reach adjNode+ numWays to reach node
                    ways[adjNode] = (ways[adjNode]+ ways[node])%MOD;
                }
            }
        }


        //      lastNode
        return ways[n-1]%MOD;
       
    }
};