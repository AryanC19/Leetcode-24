class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sMap(256, -1), tMap(256, -1);
        
        for(int i = 0; i < s.length(); i++) {
            if(sMap[s[i]] != tMap[t[i]]) return false;
            sMap[s[i]] = i;
            tMap[t[i]] = i;
        }
        return true;
    }
};