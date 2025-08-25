class Solution {
public:
    int n, m;

    void goUp(int& i, int& j, vector<vector<int>>& mat, vector<int>& ans) {
        while (i >= 0 && j < m) {
            ans.push_back(mat[i][j]);
            i--;
            j++;
        }
        // move to next valid start
        if (j < m)
            i = 0;
        else {
            i = i + 2;
            j = m - 1;
        } // handle last column
    }

    void goDown(int& i, int& j, vector<vector<int>>& mat, vector<int>& ans) {
        while (i < n && j >= 0) {
            ans.push_back(mat[i][j]);
            i++;
            j--;
        }
        // move to next valid start
        if (i < n)
            j = 0;
        else {
            j = j + 2;
            i = n - 1;
        } // handle last row
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<int> ans;
        int i = 0, j = 0;
        bool dir = true;

        while (ans.size() < n * m) {
            if (dir) {
                goUp(i, j, mat, ans);
            } else {
                goDown(i, j, mat, ans);
            }
            dir = !dir;
        }
        return ans;
    }
};
