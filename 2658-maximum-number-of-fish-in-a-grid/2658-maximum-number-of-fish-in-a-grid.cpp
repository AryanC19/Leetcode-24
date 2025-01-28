class Solution {
public:
    int maxFish = 0;
    int m, n;
    
    int func(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == 0)
            return 0;
        
        vis[i][j] = 1;
        int ans = grid[i][j];
        
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (auto& dir : dirs) {
            int ni = dir.first + i;
            int nj = dir.second + j;
            ans += func(ni, nj, grid, vis);
        }
        
       // vis[i][j] = 0; 
        return ans;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, func(i, j, grid, vis));
                }
            }
        }
        
        return maxFish;
    }
};
