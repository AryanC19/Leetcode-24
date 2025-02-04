class Solution {
public:

    void dfs(int bomb,vector<int> & exploded, unordered_map<int,vector<int> > &adjList,int &count){

        exploded[bomb]=1;

        for(auto bombs: adjList[bomb]){
            if(!exploded[bombs]){
                count++;
                dfs(bombs,exploded,adjList,count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();

        unordered_map<int,vector<int> > adjList;

        int maxBombs=0;


        for(int i=0;i<n;i++){

            double x1=bombs[i][0];
            double y1=bombs[i][1];
            int r1=bombs[i][2];

            for(int j=0;j<n;j++){

                if(i==j) continue;

                double x2=bombs[j][0];
                double y2=bombs[j][1];
                int r2=bombs[j][2];

                double d= sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

                if(r1>=d){
                    adjList[i].push_back(j);
                }
            }
        }

        

        for(int i=0;i<n;i++){
            int count=1;
            vector<int> exploded(n,0);
            dfs(i,exploded,adjList,count);
            maxBombs=max(maxBombs,count);
        }
        return maxBombs;

    }
};