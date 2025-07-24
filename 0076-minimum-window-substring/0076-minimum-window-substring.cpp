class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();

        int cnt=t.size();

        int l=0,r=0;

        vector<int> freq(128);
        for(char c: t) freq[c]++;
        int sInd=-1, len=INT_MAX;
        while(r<n){
            if(freq[s[r]] >0){
                cnt--;
            }
            freq[s[r]]--;
            while(cnt==0){
                if(r-l+1 <len){
                    len=r-l+1;
                    sInd=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) cnt++;
                l++;
            }
            r++;
        }
        return sInd == -1 ? "" : s.substr(sInd, len);

    }
};