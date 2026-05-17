class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dist(n,vector<int>(m,-1));

        queue<vector<int>> que;

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(mat[i][j]==0){
                    que.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

/*
        mutli source BFS. nodes already populated. simultaneous processing of nodes. 
         running bfs from 0->1, since tc mxn. instead if ran from all 1s->0, from each 1 will have to run. tc (mxn)^2
         from 0,1 can use prev ans to compute next ans. res [0][1] =res [0][0]+1, and res[0][2]= res [0][1] +1 and so on 


        why only 1 pass waht if another 0 has better dist? 
        mutli source BFS processes nodes simult. so its not like the 1st 0 in the queu will finish computng, then the 2nd 0
        rather 1st 0 in 1que processed to its layer1 , then 2nd 0 in queue procesed to its layer 1, then
        1st 0s 1st layer's 1node processed to its layer 1, and so on .  

best ex

  0 1 1
  1 1 1 
  1 1 0

if u think first 0 in queu preocesed entirely
wrong ans
 0 1 2
 1 2 3
 2 3 0

but since its layer by layer simult
0 1 2
1 2 1
2 1 0
*/


    // mutli source bfs

        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};

        while(!que.empty()){

            vector<int> temp= que.front();
            que.pop();
            int i=temp[0];
            int j=temp[1];

            for(auto &dir: dirs){
                int ni= i+dir[0];
                int nj= j+dir[1];
                //mistake : if belwo if loop was doing dist[ni][nj]!=-1 and getting TLe. we want to visit -1 cells not visit visited cells.
                // the ==-1 is our visited method
                if(ni< n && nj <m && ni>=0 && nj>=0 && dist[ni][nj]==-1){
                    dist[ni][nj]= dist[i][j]+1;
                    que.push({ni,nj});
                }
            }
        }

        return dist;
    }
};