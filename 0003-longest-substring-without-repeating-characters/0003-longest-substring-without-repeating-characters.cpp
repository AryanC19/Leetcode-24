class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        unordered_map<char,int> mpp;

        int l=0,r=0;
        int maxLen=-1e9;

        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(l,mpp[s[r]]+1);
                maxLen=max(maxLen,r-l+1);
            }
            mpp[s[r]]=r;
            r++;
        }
        return maxLen==-1e9 ?0 :maxLen;
    }
};