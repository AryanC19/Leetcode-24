class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mpp;


        int n=s.size();
        int m=t.size();

        if(n!=m) return false;


        for(int i=0;i<n;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]=t[i];
            }else{
                if(mpp[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};