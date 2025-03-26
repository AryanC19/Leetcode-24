class DSU {
    vector<int> size, parent, rank;
    int extra = 0;

public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // Added missing rank vector
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int x) {
        if (parent[x] == x) return x;  // Fixed '=' to '=='
        return parent[x] = findUParent(parent[x]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) {
            extra++;
            return;
        }

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;  // Fixed incorrect rank increment
        }
    }

    int getExtra() { return extra; }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;  // Not enough cables

        DSU ds(n);  

        for (auto i : connections) {
            int a = i[0];
            int b = i[1];

            ds.unionByRank(a, b);  
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUParent(i) == i) components++;
        }

        return (ds.getExtra() >= components - 1) ? components - 1 : -1;
    }
};

