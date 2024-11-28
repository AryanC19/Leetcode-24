class Solution {
public:

    typedef pair<int,pair<int,int> > P;
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int minDist=INT_MAX;

        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        const vector<pair<int,int> > dirs= {{0,1},{1,0},{-1,0},{0,-1}};
        // dist , <i ,j>
        priority_queue<P,vector<P>, greater<P>> pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});
        

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            int w=p.first;
            int i=p.second.first;
            int j=p.second.second;
                if (i == n-1 && j == m-1) {
                    return w;
                }
            auto valid= [&](int i,int j){
                return i<n && j<m && i>=0 && j>=0;
            };

            for(auto dir:dirs){
                int ni=i+dir.first;
                int nj=j+dir.second;

                if(valid(ni,nj)){
                 
                    int nw=(grid[ni][nj]==0) ? w :  w+1;

                    if(nw<dist[ni][nj]){
                        dist[ni][nj]=nw;
                        pq.push({nw,{ni,nj}});
                    }

                }
            }
        }



        return -1;
    }
};