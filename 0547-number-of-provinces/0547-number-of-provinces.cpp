class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        
        unordered_map<int,vector<int> > mpp;

        int n=graph.size();


        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(graph[i][j]==1){

                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }

        int cnt=0;

        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            
            if(!vis[i]){
                cnt++;
                vis[i]=1;
                queue<int> q;   
                q.push(i);  
                while(!q.empty()){
                    auto p=q.front();
                    q.pop();
                    for(auto &node:mpp[p]){
                        if(!vis[node]){
                            vis[node]=1;
                            q.push(node);
                        }
                    }
                }
            }
        }

        return cnt;
    }
};