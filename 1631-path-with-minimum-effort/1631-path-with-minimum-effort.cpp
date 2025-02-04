class Solution {
public:
    typedef tuple<int,int,int> T;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();


        priority_queue<T,vector<T> , greater<T> > pq;



        vector<vector<int>> res(m,vector<int> ( n,INT_MAX));


        res[0][0]=0;

        vector<vector<int> > dirs= {{0,1},{1,0},{-1,0},{0,-1}};
        pq.push({0,0,0});


        auto isSafe=[&](int x,int y){
            return x>=0 && y>=0 && x<m && y<n;
        };
        while(!pq.empty()){


            auto[diff,x,y]=pq.top();
            pq.pop();   

            for(auto &dir:dirs){


                int nx=x+dir[0];
                int ny=y+dir[1];

                if(isSafe(nx,ny)){
                    
                    //abs diff bw adjCells
                    int absDiff=abs(heights[x][y]-heights[nx][ny]);

                    //effort= max of all diff along path, so maxDiff=effort
                    int maxDiff=max(diff,absDiff);

                    // only update res if the maxDiff < res[nx][ny]
                    // ie found a better effort for that cell


                    // res[x][y] means the **minimum effort required** to reach cell (x, y) 
                    // from the starting cell (0,0).

                    if(res[nx][ny]> maxDiff){
                        res[nx][ny]=maxDiff;
                        pq.push({maxDiff,nx,ny});
                    }
                }
            }
        }
        

        // after all exploratino, return min effort from 0,0 to reach cell m-1,n-1 which is what is asked
        return res[m-1][n-1];
    }
};