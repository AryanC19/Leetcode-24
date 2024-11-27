class Solution {
public:
    int bfs(unordered_map<int,vector<int>> &adj,int n){


        queue<int> q;
        q.push(0);
        vector<int> dist(n,-1);
        dist[0]=0;
        while(!q.empty()){

            int p=q.front();
            q.pop();

            for(auto i:adj[p]){

                if(dist[i]==-1){
                    dist[i]=1+dist[p];
                    q.push(i);
                }
            }
        }

        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;
        for(auto &i:queries){
            adj[i[0]].push_back(i[1]);
            ans.push_back(bfs(adj,n));
        }
        return ans;

    }
};