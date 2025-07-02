class Solution {
public:
    bool isZero(unordered_map<char, int> &freqMap){
        for(auto &it:freqMap){
            if(it.second!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> freqMap;

        for(auto i:p) freqMap[i]++;
        int l=0,r=0;
        int n=s.size();
        int k=p.size();
        vector<int> ans;
        while(r<n){

            freqMap[s[r]]--;

            if(r-l+1==k){
                if(isZero(freqMap)) ans.push_back(l);
                freqMap[s[l]]++;
                l++;
            }
            r++;
        }
        return ans;
    }
};