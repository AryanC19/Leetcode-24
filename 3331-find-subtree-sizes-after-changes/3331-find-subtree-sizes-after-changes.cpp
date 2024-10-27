class Solution {
public:
    string s;
    // Find closest ancestor with same character
    int findClosestAncestor(int node, vector<int>& parent) {
        int curr = parent[node];
        while(curr != -1) {
            if(s[curr] == s[node]) return curr;
            curr = parent[curr];
        }
        return -1;
    }
    
    int getSize(int node, map<int,vector<int>> &adj) {
        int size = 1;
        for(auto child : adj[node]) {
            size += getSize(child, adj);
        }
        return size;
    }
    
    vector<int> findSubtreeSizes(vector<int>& parent, string so) {
        map<int,vector<int>> adj;
        int n = parent.size();
        vector<int> ans(n, 1);
        s = so;
        
        // Build initial adjacency list
        for(int i = 0; i < n; i++) {
            if(parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }
        
        // Store all changes that need to be made
        vector<pair<int,int>> changes;  // {node, new_parent}
        for(int i = 1; i < n; i++) {
            int closest = findClosestAncestor(i, parent);
            if(closest != -1 && closest != parent[i]) {
                changes.push_back({i, closest});
            }
        }
        
        // Apply all changes simultaneously
        for(auto change : changes) {
            int node = change.first;
            int new_parent = change.second;
            // Remove from old parent
            auto it = find(adj[parent[node]].begin(), adj[parent[node]].end(), node);
            if(it != adj[parent[node]].end()) {
                adj[parent[node]].erase(it);
            }
            // Add to new parent
            adj[new_parent].push_back(node);
        }
        
        // Calculate final sizes
        for(int i = 0; i < n; i++) {
            ans[i] = getSize(i, adj);
        }
        
        return ans;
    }
};