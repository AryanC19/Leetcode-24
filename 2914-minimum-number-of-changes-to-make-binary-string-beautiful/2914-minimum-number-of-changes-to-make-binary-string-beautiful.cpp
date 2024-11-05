class Solution {
public:
   
    int minChanges(string s) {
        
        int cnt=0;
        for(int i=1;i<s.size();){
            if(s[i]!=s[i-1]) cnt++;
            i+=2;
        }
        return cnt;
    }
};