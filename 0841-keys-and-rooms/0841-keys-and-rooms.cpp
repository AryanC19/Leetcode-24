class Solution {
public:

/**/
    void func(int i, vector<vector<int>>& rooms , vector<int >& vis){
        if(vis[i]) return;
        vis[i]=1;
        for(int keys: rooms[i]){
            func(keys, rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n);
        func(0,rooms,vis);

        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};