class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        unordered_map<char,int> mpp;
        int l=0,r=0;
        int ans=0;
        while(r<n){

            while(mpp.find(s[r])!=mpp.end()){
                mpp[s[l]]--;
                l++;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
            }

            ans=max(ans,r-l+1);
            mpp[s[r]]++;
            r++;
        }
        return ans;
    }
};