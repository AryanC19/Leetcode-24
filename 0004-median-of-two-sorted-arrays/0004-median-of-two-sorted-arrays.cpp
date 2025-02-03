class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int k = n + m, midInd = k / 2;
        int mid = 0, preMid = 0, i = 0, j = 0, cnt = 0;

        while (i < n || j < m) {
            int val;
            if (i < n && (j >= m || nums1[i] < nums2[j])) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            if (cnt == midInd - 1) preMid = val;
            if (cnt == midInd) {
                mid = val;
                break;
            }
            cnt++;
        }

        return (k % 2 == 0) ? (mid + preMid) / 2.0 : mid;
    }
};
