class Solution {
public:
    string makeFancyString(string s) {
        
        int n =s.size();

        for(int i=2;i<n;i++){
            if(s[i-2]==s[i-1] && s[i-1]==s[i]){
                s[i-2]='Z';
            }
        }
        string ans="";
        for(auto i:s){
            if(i!='Z') ans+=i;
        }
        return ans;
    }
};