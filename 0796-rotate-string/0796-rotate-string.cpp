class Solution {
public:
    bool rotateString(string s, string goal) {
        s+=s;

        if(s.size()/2!=goal.size()) return false;

        for(int i=0;i<s.size();i++){

            if(goal==s.substr(i,s.size()/2)) return true;
        }
        return false;

    }
};