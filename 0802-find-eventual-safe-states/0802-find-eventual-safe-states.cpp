class Solution {
public:

    unordered_map<int,vector<int>> adjList;  

    bool isCyclic(int node,vector<int> &vis,vector<int> &inRec){
        vis[node]=true;
        inRec[node]=true;
        for(auto &nodes:adjList[node]){
            if(!vis[nodes] && isCyclic(nodes,vis,inRec)){
                return true;
            }else if(vis[nodes] && inRec[nodes]){
                return true;
            }
        }
        vis[node]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> inRec(n,0);
        vector<int> safeNodes;
        //init adjList
        for(int i=0;i<n;i++){
            for(auto &node:graph[i]){
                adjList[i].push_back(node);
            }
        }


        /*
        
        0->1,2
        1->2,3
        2->5
        3->0
        4->5
        *5->
        *6->
        */

        for(int i=0;i<n;i++){
            if(!vis[i] && !isCyclic(i,vis,inRec)){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;

    }
};