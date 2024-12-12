class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,j=0;
        
        while(i<n){
            char current = chars[i];
            int cnt=1;
            
            // Count consecutive characters
            while(i+1 < n && chars[i+1] == current){
                i++;
                cnt++;
            }
            
            // Write the character
            chars[j++] = current;
            
            // Write count if > 1
            if(cnt > 1){
                for(char c:to_string(cnt)){
                    chars[j++] = c;
                }
            }
            
            i++;
        }
        return j;
    }
};