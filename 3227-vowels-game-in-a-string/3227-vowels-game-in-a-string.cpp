class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vow={'a','e','i','o','u'};
        int cnt=0;
        for(auto i:s) {
            if(vow.find(i)!=vow.end()) cnt++;
        }
       
        
        return cnt>0 ?true:false;
    }
};