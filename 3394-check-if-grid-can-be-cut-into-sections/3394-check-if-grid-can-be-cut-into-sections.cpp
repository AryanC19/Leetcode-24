class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> xarr, yarr, mergedX, mergedY;

        // Separate intervals for x and y
        for (auto& rect : rectangles) {
            xarr.push_back({rect[0], rect[2]});
            yarr.push_back({rect[1], rect[3]});
        }

        // Sort the intervals
        sort(begin(xarr), end(xarr));
        sort(begin(yarr), end(yarr));

        // Merge x intervals
        for (auto& i : xarr) {
            if (mergedX.empty() || mergedX.back()[1] <= i[0]) {
                mergedX.push_back(i);
            } else {
                mergedX.back()[1] = max(mergedX.back()[1], i[1]);
            }
        }

        // Merge y intervals
        for (auto& i : yarr) {
            if (mergedY.empty() || mergedY.back()[1] <= i[0]) {
                mergedY.push_back(i);
            } else {
                mergedY.back()[1] = max(mergedY.back()[1], i[1]);
            }
        }

        // Check if we can make valid cuts in either direction
        // Valid if we can divide into exactly 3 sections
        bool validX = mergedX.size() >= 3;
        bool validY = mergedY.size() >= 3;

        return validX || validY;
    }
};
