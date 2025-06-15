class Solution {
public:
    bool isOutOfOrder(const string &a, const string &b, const unordered_map<char, int> &mpp)        
    {

        int n = min(a.length(), b.length());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                return mpp.at(a[i]) > mpp.at(b[i]);
            }
        }
        return a.size() > b.size(); 

    }

    bool isAlienSorted(vector<string>& words, string order) {
        bool res;
        unordered_map<char,int> mpp;
       for (int i = 0; i < order.size(); i++) {
        mpp[order[i]] = i;
        }

    

        for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (isOutOfOrder(words[i], words[j], mpp)) {
                return false;
            }
        }}
                return true;

    }
};