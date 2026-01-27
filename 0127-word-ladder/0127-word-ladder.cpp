class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> bankset(wordList.begin(),wordList.end());

        //         word     no. of words in the shortest transformation seq
        queue<pair<string, int>> q;

        q.push({beginWord,1});
        while(!q.empty()){
            pair<string,int> node= q.front();
            q.pop();
            string word=node.first;
            int steps=node.second;

            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                string temp=word;
                for(int ch='a';ch<='z';ch++){
                    char c=temp[i];
                    temp[i]=ch;
                    if(bankset.count(temp)){
                        bankset.erase(temp);
                        q.push({temp,steps+1});
                    }
                    temp[i]=c;
                }
            }
        }

        return 0;
    }
};