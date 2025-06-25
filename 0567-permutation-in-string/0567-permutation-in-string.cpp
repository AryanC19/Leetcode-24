class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        

        unordered_map<int,int> freqMap;

        if(s1.size() >s2.size() ) return false;
        for(auto &i:s1) freqMap[i]++;

        unordered_map<int,int> pattern;

        for(int i=0;i<s1.size();i++){
            pattern[s2[i]]++;
        }
        
        if(pattern==freqMap) return true;

        int l=0; int r=s1.size();

        while(r<s2.size()){
            pattern[s2[r]]++;
            pattern[s2[l]]--;
            if(pattern[s2[l]]==0) pattern.erase(s2[l]);
            if(pattern==freqMap) return true;
            r++;
            l++;
        }

        return false;

    }
};