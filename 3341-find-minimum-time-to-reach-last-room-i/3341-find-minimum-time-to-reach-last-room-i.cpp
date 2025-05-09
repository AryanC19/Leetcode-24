class Solution {
public:
    typedef tuple<int,int,int> T;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) return t;

            vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];

                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

                int wait = max(0, moveTime[ni][nj] - t);
                int currTime = t + wait + 1;

                if (dist[ni][nj] > currTime) {
                    dist[ni][nj] = currTime;
                    pq.push({currTime, ni, nj});
                }
            }
        }
        return -1;
    }
};
