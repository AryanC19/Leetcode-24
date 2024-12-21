class Solution {
public:
    static const int MOD = 1e9 + 7; // Define the modulo value
    int dp[300][300][16];          // Use an int array for memoization
    int m, n;

    int func(int i, int j, vector<vector<int>>& grid, int k, int XOR) {
        // Out of bounds
        if (i >= m || j >= n) return 0;

        // Base case: reached the bottom-right cell
        if (i == m - 1 && j == n - 1) {
            return (XOR ^ grid[i][j]) == k;
        }

        // Check memoization
        if (dp[i][j][XOR] != -1) return dp[i][j][XOR];

        // Calculate paths and apply modulo
        int right = func(i, j + 1, grid, k, XOR ^ grid[i][j]);
        int down = func(i + 1, j, grid, k, XOR ^ grid[i][j]);

        // Store result modulo MOD
        return dp[i][j][XOR] = (right + down) % MOD;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // Initialize dp array with -1
        memset(dp, -1, sizeof(dp));

        // Compute the result with modulo
        return func(0, 0, grid, k, 0);
    }
};
