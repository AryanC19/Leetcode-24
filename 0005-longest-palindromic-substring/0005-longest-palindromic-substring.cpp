class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        //int ans=INT_MAX;
        string ans="";
        //even

        for(int i=0;i<n;i++){
            int l=i,r=i;
            int cnt=0;
            while( l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            l++;r--;
 
            if(ans.size()< r-l+1){
                ans=s.substr(l,r-l+1);
            }
        }

        //odd

        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            int cnt=0;
            while( l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            l++;r--;
            if(ans.size()< r-l+1){
                ans=s.substr(l,r-l+1);
            }
        }

        return ans;
    }
};