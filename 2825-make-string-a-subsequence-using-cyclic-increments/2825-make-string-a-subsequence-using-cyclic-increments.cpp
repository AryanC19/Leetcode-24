class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();
        int i=0,j=0;


        while(i<n && j<m){
            
            if( ((s1[i]-'a'+1)%26 +'a' ==s2[j] ) || (s1[i] == s2[j])){ 
                i++;j++;
            }
            else{
                i++;
            }
        }
        return j==m;

    }
};