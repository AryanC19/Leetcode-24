class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // TC: O(V (E + V) log V + V²) 
        // SC :  O(V² + E).

        vector<vector<int> > mat;


        unordered_map<int,vector<pair<int,int>> > adjList;

        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }


        //dijsktra for each src. single source shortest path algo

        for(int src=0;src<n;src++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
            vector<int> dist(n,INT_MAX);
            dist[src]=0;
            //     dist,node
            pq.push({0,src});
            while(!pq.empty()){
                auto [wt,node]=pq.top();
                pq.pop();
                for(auto &[child,childWt]:adjList[node]){    
                    if(wt +childWt <dist[child]){
                        dist[child]=wt+childWt;
                        pq.push({wt +childWt , child});
                    }
                }
            } 
            mat.push_back(dist);
        }

        int cntCity=n;
        int city=-1;

        for(int i=0;i<n;i++){

            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j] <= distanceThreshold) cnt++;
            }
            // since i =0 -> n , the last updated city will be highest thus satisfying the condition 
            // of highest city num when min cities r equal
            if(cnt<=cntCity){
                cntCity=cnt;
                city=i;
            }
        }
        return city;
    }
};