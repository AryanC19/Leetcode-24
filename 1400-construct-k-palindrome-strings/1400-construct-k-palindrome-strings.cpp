class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(k>s.size()) return false;
        unordered_map<int,int> mpp;
        for(auto i:s) mpp[i]++;
        int oddCnt=0;
        for(auto i:mpp){
            if(i.second%2!=0) oddCnt++;
        }
        return oddCnt<=k;
    }
};