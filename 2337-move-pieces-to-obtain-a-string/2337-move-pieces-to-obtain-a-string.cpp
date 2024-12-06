class Solution {
public:
    bool canChange(string str, string res) {
        
        int n=str.length();

        int i=0,j=0;


        while(i<n || j<n){

            while(i<n && str[i]=='_') i++;
            while(j<n && res[j]=='_') j++;

            if(i==n || j==n) {return i==n && j==n;}

            if(str[i]!=res[j] ) return false;
            if(str[i]=='L' && i<j) return false;
            if(str[i]=='R' && i>j) return false;
            i++;j++;
        }

        return true;
    }
};