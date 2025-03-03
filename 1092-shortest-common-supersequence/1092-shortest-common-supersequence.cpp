class Solution {
public:
    vector<vector<int>> dp;

    int lcs(int i, int j, string &s1, string &s2) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);
        return dp[i][j] = max(lcs(i, j - 1, s1, s2), lcs(i - 1, j, s1, s2));
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        dp.assign(n, vector<int>(m, -1));  // Ensure dp size is (n x m)

        int lcsLen = lcs(n - 1, m - 1, s1, s2);

        int i = n - 1, j = m - 1;
        string scs = "";

        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                scs += s1[i];
                i--, j--;
            } else {
                if (j > 0 && (i == 0 || dp[i][j - 1] > dp[i - 1][j])) {
                    scs += s2[j--];
                } else {
                    scs += s1[i--];
                }
            }
        }

        while (i >= 0) scs += s1[i--];
        while (j >= 0) scs += s2[j--];

        reverse(scs.begin(), scs.end());
        return scs;
    }
};
