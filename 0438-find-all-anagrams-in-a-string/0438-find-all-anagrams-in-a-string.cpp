class Solution {
public:
    //RUPEEK COUDNT SOLVE FUCKIGN IDIOt 
    vector<int> findAnagrams(string text, string word) {
        unordered_map<char, int> wordMap, textMap;

        for(auto c: word) wordMap[c]++;
        int wordSize=word.size();
        int textSize=text.size();

        vector<int> ans;
        int l=0, r=wordSize;

        for(int i=0;i<wordSize;i++){
            textMap[text[i]]++;
        }
        if(textMap==wordMap) ans.push_back(0);

        while(r<textSize){
            textMap[text[r]]++;
            textMap[text[l]]--;
            if(textMap[text[l]]==0) textMap.erase(text[l]);
            r++;
            l++;
            if(textMap==wordMap) ans.push_back(l);
        }

        return ans;
    }
};