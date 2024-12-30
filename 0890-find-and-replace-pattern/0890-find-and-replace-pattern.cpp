class Solution {
public:

    bool isIsomorphic(string &word, string &pattern) {

        unordered_map<char,bool> used;
        unordered_map<char,char> map;

        
        for(int i=0;i<pattern.size();i++){
            char ch1=pattern[i];
            char ch2=word[i];

            if(map.count(ch1)){
                if(map[ch1]!=ch2) return false;
            }else{
                if(used[ch2]==true) return false;
                used[ch2]=true;
                map[ch1]=ch2;
            }
        }
        return true;
    
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        
        vector<string> ans;

        for(auto &word:words){  
            if(isIsomorphic(word,pattern)) ans.push_back(word);
        }
        return ans;
    }
};