class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for (int i = 0; i < k - 1; i++) {  
            colors.push_back(colors[i]);  // extend array for circular behavior
        }

        int ans = 0, l = 0;
        for (int r = 1; r < n + k - 1; r++) {
            if (colors[r] == colors[r - 1]) { // Reset if non-alternating
                l = r;
            }
            if (r - l + 1 == k) { 
                ans++;
                l++; 
            }
        }
        return ans;
    }
};
