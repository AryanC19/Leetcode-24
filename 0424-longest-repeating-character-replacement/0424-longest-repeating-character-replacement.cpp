class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();
        
        int ans=0;
        for(char c='A';c<='Z';c++){
            int l=0,r=0;
            int T=0;
            while(r<n){
                T+= s[r]==c ?1:0;

                // The key change is here - we need to check if replacements needed
                // exceed k, not if matching characters exceed k instead (T>k),
                while((r - l + 1) - T >k){
                    T-=s[l]==c ?1:0;
                    l++;
                }
                // (r-l+1)-T denotes the length of the current string minus the length of the characters.
                // which equals the len of replacements.

                //tc O(26 *n) ~ O(n)
                ans=max(ans,r-l+1);
                r++;
            }   
        }

        return ans;
    }
};