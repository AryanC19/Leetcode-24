class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }
        int province=0;
        for(int i=0;i<mpp.size();i++){
            if(!visited[i]){
                province++;
                
                queue<int> q;
                visited[i]=1;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto nodes:mpp[node]){
                        if(!visited[nodes]){
                            visited[nodes]=1;
                            q.push(nodes);
                        }
                    }
                }
            }
        }

        return province;
    }
};