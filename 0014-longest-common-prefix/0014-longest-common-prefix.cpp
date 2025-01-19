class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string pref=strs[0];
        if(pref.size()==0) return pref;
        for(int i=1;i<n;i++){
            int j=0;
            string temp="";
            while(j<pref.size() && strs[i][j]==pref[j]){
                temp+=pref[j];
                j++;
            }
            pref=temp;
            if(temp=="") break;
            
        }
        return pref;
    }
};