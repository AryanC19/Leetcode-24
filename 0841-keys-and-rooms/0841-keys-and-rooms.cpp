class Solution {
public:

    void dfs(int node,vector<int> &vis,unordered_map<int,vector<int> > &mpp){

        vis[node]=1;
        for(auto &child:mpp[node]){
            if(!vis[child]) dfs(child,vis,mpp);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int> > mpp;
        

        for(int i=0;i<rooms.size();i++){
            
            for(auto &j:rooms[i]){
                mpp[i].push_back(j);
            }
        }


        vector<int> vis(rooms.size(),0);

        dfs(0,vis,mpp);

        for(auto i:vis) if(i==0) return false;
        return true;
        
    }
};