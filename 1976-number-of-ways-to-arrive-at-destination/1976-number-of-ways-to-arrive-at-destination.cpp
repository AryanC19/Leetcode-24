class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> adjList;

        // Construct adjacency list
        for (auto& i : roads) {
            int u = i[0], v = i[1], wt = i[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        // Min heap (priority queue)
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});  // {distance, node}

        // src -> shortest distance, number of ways
        vector<P> dist(n, {LLONG_MAX, 0});  //  Use LLONG_MAX to avoid overflow
        dist[0] = {0, 1};  // Source node initialized

        while (!pq.empty()) {
            auto [wt, node] = pq.top();  // Use long long for `wt`
            pq.pop();

            // Optimization: Skip outdated distances
            if (wt > dist[node].first) continue;  

            for (auto [childNode, childDist] : adjList[node]) {
                ll newDist = wt + childDist;
                
                if (newDist < dist[childNode].first) {  
                    //  Found a shorter path, update distance and ways count
                    dist[childNode].first = newDist;
                    dist[childNode].second = dist[node].second;
                    pq.push({newDist, childNode});
                } else if (newDist == dist[childNode].first) {  
                    // If same shortest path found, add ways
                    dist[childNode].second = (dist[childNode].second + dist[node].second) % MOD;
                }
            }
        }

        return dist[n - 1].second;  //  Return number of ways to reach destination
    }
};
