class Solution {
public:
//linear tc and cosntast sc
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int tot = n + m;
        int ind = tot / 2;

        double ans = 0;
        bool even = (tot % 2 == 0);
        
        int prev1 = 0, prev2 = 0;
        int i = 0, j = 0, cnt = 0;
        
        while (i < n || j < m) {
            int curr;
            
            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
            
            if (cnt == ind - 1) prev1 = curr;
            if (cnt == ind) {
                prev2 = curr;
                break;
            }
            cnt++;
        }

        return even ? (prev1 + prev2) / 2.0 : prev2;
    }
};
