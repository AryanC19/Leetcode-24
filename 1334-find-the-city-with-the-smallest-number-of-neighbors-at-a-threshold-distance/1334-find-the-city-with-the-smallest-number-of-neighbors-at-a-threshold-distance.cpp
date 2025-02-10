class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        //floydWarshal


        int cnt=0;

        int city=-1;
        int cntMax=0;


        vector<vector<int> > dist (n,vector<int> (n,INT_MAX));


        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        // floyd warshal
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] == INT_MAX || dist[via][j] ==INT_MAX)
                        continue;
                    dist[i][j]= min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }

        /*now comupting on the distance matrix, we find the city 
        which has the greatest numebr and the smallest num of neighbours withing     thershold dist
        */


        int cntCity=n;
        int cityNo=-1;

        for(int city=0;city<n;city++){

            int cnt=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(dist[city][adjCity]<=distanceThreshold) cnt++;
            }

            if(cnt<=cntCity){
                cntCity=cnt;
                cityNo=city;
            }
        }

        return cityNo;

    }
};