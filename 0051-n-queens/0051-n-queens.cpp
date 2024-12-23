class Solution {
public:
    bool isSafe(int r, int c, vector<string>& board, int n) {
        int tr = r, tc = c;
        // left
        while (tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;
            tc--;
        }

        // leftdiagup
        tr = r, tc = c;
        while (tr >= 0 && tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;

            tr--;
            tc--;
        }
        tr = r, tc = c;
        // leftdiagdwn
        while (tr < n && tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;
            tr++;
            tc--;
        }

        return true;
    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               int n) {
        // missed this too
        if (col == n) {
            ans.push_back(board);
            return;
        }
        // messed this loop, didnt remember to pass col in solve func
        for (int row = 0; row < n; row++)
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string row = string(n, '.');
        for (int i = 0; i < n; i++) {
            // cout<<row<<endl;
            board.push_back(row);
        }

        solve(0, board, ans, n);
        return ans;
    }
};