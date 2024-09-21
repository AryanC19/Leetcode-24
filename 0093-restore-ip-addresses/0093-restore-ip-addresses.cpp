class Solution {
public:
    int n;

    // Helper function to check if a segment is a valid IP segment
    bool isIP(string S) {
        int val = stoi(S);
        if ((S[0] == '0' && S.size() > 1) || val > 255) return false;
        return true;
    }

    // Recursive function to restore IP addresses
    void solve(int i, int splits, string curr, string s, vector<string> &ans) {
        if (i == n && splits == 4) {
            curr.pop_back(); // Remove extra dot at the end
            ans.push_back(curr);
            return;
        }

        if (splits >= 4) return; // Too many splits, invalid case

        // Try placing 1, 2, or 3 length segments
        if (i + 1 <= n) {
            solve(i + 1, splits + 1, curr + s.substr(i, 1) + ".", s, ans);
        }
        if (i + 2 <= n && isIP(s.substr(i, 2))) {
            solve(i + 2, splits + 1, curr + s.substr(i, 2) + ".", s, ans);
        }
        if (i + 3 <= n && isIP(s.substr(i, 3))) {
            solve(i + 3, splits + 1, curr + s.substr(i, 3) + ".", s, ans);
        }
    }

    // Main function to restore IP addresses
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        if (n > 12 || n < 4) return {}; // IP address must be between 4 and 12 characters
        vector<string> ans;
        solve(0, 0, "", s, ans);
        return ans;
    }
};
