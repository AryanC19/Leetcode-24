class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        
        //choose any character of the string and change
        // it to any other uppercase English character
        // no of uppercase English->26

        // problem translates to length of longest substr with at max K replaced cahracters

        int maxlen=0;


        for(int i=0;i<26;i++){
            char c='A'+i;
            int l=0,r=0;

            int T=0;

            while(r<n){

                if(s[r]==c) T++;

// while the length of the current window minus the count of character 'c' exceeds K,
// it means there are more than K characters in the window that are not 'c'.
// to maintain at most K replacements, we need to shrink the window from the left. 
                while((r-l+1)-T>k){
                    T-= s[l]==c ?1:0;
                    l++;
                }
                maxlen=max(maxlen,r-l+1);
                r++;
            }
        }

        return maxlen;

    }
};