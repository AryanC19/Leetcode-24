class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); 
        int l = 0, h = citations.size() - 1, ans = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (citations[m] >= m + 1) { // check if at least (m+1) papers have (m+1) citations
                ans = m + 1; 
                l = m + 1;  
            } else {
                h = m - 1;   
            }
        }
        return ans;
    }
};
