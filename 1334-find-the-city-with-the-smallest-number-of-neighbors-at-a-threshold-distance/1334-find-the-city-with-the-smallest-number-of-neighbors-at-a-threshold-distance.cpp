class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // standard djisktras? nononono floyd warsahal . multi source shortest path

        /*
            build shortest distance matrix using floyd
            using the distThreshold, 
        */
        // gibberish naming and low effort ccode, refer previous submission for better undersstanign. 
        // forgot floyd warshal after 1 week of slacking ggwp fag
        // build adjList

        vector<vector<int> > mat(n,vector<int> (n,INT_MAX));
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] < INT_MAX && mat[via][j] < INT_MAX) { 
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }

        int cntCity=-1;
        int minCities=n;

        for(int i=0;i<n;i++){

            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j] <=distanceThreshold){
                    cnt++;
                }
            }

            if(minCities>=cnt){
                minCities=cnt;
                cntCity=i;
            }

        }
        return cntCity;
    }
};