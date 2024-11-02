class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string token="";

        while(ss>>token){
            words.push_back(token);
        }

        int n=words.size();
        for(int i=1;i<n;i++){
            if(words[i-1][words[i-1].size()-1] !=words[i][0]) return false;
        }

        if(words[0][0]!=words[n-1][words[n-1].size()-1]) return false;

        return true;
    }
};