class Solution {
public:
    bool isPalindrome(int x) {
        string st=to_string(x);
        int l=0,r=st.size()-1;
        while(l<r){
            if(st[l++]!=st[r--]) return false;
        }
        return true;
    }
};