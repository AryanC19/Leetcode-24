class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        stringstream ss(sentence);
        string token="";

        vector<string> words;
        int n=sw.size();

        while(getline(ss,token,' ')){
            words.push_back(token);
        }


        int indPrefix=-1;
        for(int i=0;i<words.size();i++){
            
            int j=0,k=0;
            while(j<words[i].size() && k<n) {
                if(words[i][j]!=sw[k]) break;
                else{
                    j++;k++;
                }
            }

            if(k==n){
                return i+1;
            }
        }

        return indPrefix;
    }
};