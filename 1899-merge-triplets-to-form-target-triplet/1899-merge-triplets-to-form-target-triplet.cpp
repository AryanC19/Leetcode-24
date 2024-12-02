class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        int m = triplets[0].size();

        // Map to check if each target element is achievable
        vector<bool> achieved(m, false);

        for (int i = 0; i < n; i++) {
            // Check if the triplet is valid for consideration
            if (triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]) {

                // Mark achieved elements
                for (int j = 0; j < m; j++) {
                    if (triplets[i][j] == target[j]) {
                        achieved[j] = true;
                    }
                }
            }
        }

        // Check if all target elements are achieved
        return achieved[0] && achieved[1] && achieved[2];
    }
};
