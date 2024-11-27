class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> answer;

        // Initialize the initial roads
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        auto bfs = [&]() {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(0);
            dist[0] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        q.push(neighbor);
                    }
                }
            }

            return dist[n - 1];
        };

        for (const auto& query : queries) {
            // Add the new road from the query
            adj[query[0]].push_back(query[1]);

            // Calculate the shortest path after adding this road
            int shortestDist = bfs();

            answer.push_back(shortestDist);
        }

        return answer;
    }
};