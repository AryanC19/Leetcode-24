class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int> > &adjList,vector<int> &vis,int &V, int &E){

        vis[node]=1;
        V++;
        E+= adjList[node].size();
        for(auto child:adjList[node]){
            if(!vis[child]){
                dfs(child,adjList,vis,V,E);
            }
        }
            
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         
        vector<int> vis(n,0);

        unordered_map<int,vector<int> > adjList;

        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int complete=0;

        for(int i=0;i<n;i++){
            
            if(vis[i]) continue;
            int V=0;
            int E=0;
            dfs(i,adjList,vis,V,E);
            int supposedE= (V * (V-1))/2;
            E/=2;
            if(E==supposedE) complete++;
        }

        return complete;

    }
};