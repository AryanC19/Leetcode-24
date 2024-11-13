class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0;
        int i = n-1;
        while(i>=0){
            if(s[i] == ' '){
                i--;
            }
            else{
                count++;
                i--;
                if( i>=0 && s[i]==' '){
                    break;
                }
                
            }
        }
        return count;
    }
};