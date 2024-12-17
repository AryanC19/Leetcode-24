class Solution {
public:
    typedef pair<char,int> P;
    string repeatLimitedString(string s, int k) {
        
        
        string result="";

        vector<int> freq(26,0);

        for(char &i:s) freq[i-'a']++;

        //start from last letter so we get lexicographically largest
        int i=25;
        int j=0;
        while(i>=0){

            if(freq[i]==0){
                i--;
                continue;
            }
            // to get char from ascii val int
            char ch='a'+i;
            int count= min(freq[i],k);

            result.append(count,ch);  

            freq[i]-=count;

            if(freq[i]>0){
                //find next largest char

                int j=i-1;
                while(j>=0 && freq[j]==0) j--;
                if(j<0) break;

                result.push_back('a'+j);
                freq[j]--;

            }
           
        }
        return result;
    }
};