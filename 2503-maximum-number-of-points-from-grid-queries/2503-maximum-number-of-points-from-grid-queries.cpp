class Solution {
public:
    typedef tuple<int, int, int> T;

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<T, vector<T>, greater<T>> pq;

        map<int, vector<int>> query_map;
        for (int i = 0; i < queries.size(); i++) {
            query_map[queries[i]].push_back(i);
        }

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        int points = 0;
        vector<int> ans(queries.size(), 0);
        
        for (auto &[query, indices] : query_map) {
            while (!pq.empty() && get<0>(pq.top()) < query) {
                auto [wt, i, j] = pq.top();
                pq.pop();
                points++;

                const vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
                for (auto &dir : dirs) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) {
                        vis[ni][nj] = 1;
                        pq.push({grid[ni][nj], ni, nj});
                    }
                }
            }
            for (int idx : indices) {
                ans[idx] = points;
            }
        }

        return ans;
    }
};
