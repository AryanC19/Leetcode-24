class Solution {
public:
    int n;
    set<string> st; 

    void func(string &s, vector<int> &vis, string &ds) {
        if (!ds.empty()) st.insert(ds); 
        for (int i = 0; i < n; i++) {
            if (i > 0 && s[i] == s[i - 1] && !vis[i - 1]) continue; 
            if (!vis[i]) {
                vis[i] = 1;
                ds.push_back(s[i]);
                func(s, vis, ds);
                vis[i] = 0;
                ds.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        n = tiles.size();
        string ds = "";
        vector<int> vis(n, 0);
        func(tiles, vis, ds);
        return st.size();
    }
};
