class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;

        int l=0,r=0,n=s.size(),ans=0,count=0;


        while(r<n){
            mpp[s[r]]++;

            while(mpp['a']>0 &&mpp['b']>0 &&mpp['c']>0 ){
                ans+= n-r;
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};