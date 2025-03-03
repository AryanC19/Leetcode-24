class Solution {
public:
  int solve(int left, int right, int ops, string& s, vector<vector<vector<int>>>& dp) {
    if (left > right) return 0;
    if (left == right) return 1;
    if (dp[left][right][ops] != -1) return dp[left][right][ops];

    int maxLength = max(solve(left + 1, right, ops, s, dp), solve(left, right - 1, ops, s, dp));
    int opsReq = min(abs(s[left] - s[right]), 26 - abs(s[left] - s[right]));
    if (ops >= opsReq) maxLength = max(maxLength, 2 + solve(left + 1, right - 1, ops - opsReq, s, dp));

    return dp[left][right][ops] = maxLength;
  }

  int longestPalindromicSubsequence(string s, int k) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    return solve(0, n - 1, k, s, dp);
  }
};