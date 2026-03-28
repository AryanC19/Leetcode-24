class Solution {
public:
typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<ll> rowPresum,colPresum;

        int m=grid.size();
        int n=grid[0].size();
        ll total=0;


        for(int i=0;i<m;i++){
            ll rowSum=0;
            for(int j=0;j<n;j++){
                rowSum+=grid[i][j];
                total+=grid[i][j];
            }
            rowPresum.push_back(rowSum);
        }
        ll runningRow=0;
        for(auto rowSum:rowPresum){
            runningRow+=rowSum;
            if(2*runningRow==total)  return true;
        }

        for(int j=0;j<n;j++){
            ll colSum=0;
            for(int i=0;i<m;i++){
                colSum+=grid[i][j];
            }
            colPresum.push_back(colSum);
        }

        ll runningCol=0;
        for(auto colSum:colPresum){
            runningCol+=colSum;
            if(2*runningCol==total) return true;
        }
        return false;
    }
};