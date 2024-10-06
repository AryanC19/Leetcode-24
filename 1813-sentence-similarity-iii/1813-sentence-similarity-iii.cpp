class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Extract words from both sentences
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> w1, w2;
        string word;
        
        // Push words from sentence1 into w1
        while (ss1 >> word) {
            w1.push_back(word);
        }
        
        // Push words from sentence2 into w2
        while (ss2 >> word) {
            w2.push_back(word);
        }

        // Sizes of word vectors w1 and w2
        int n = w1.size();
        int m = w2.size();
        
        // If sentence2 is longer, swap to always make w1 the longer or equal
        if (n < m) {
            swap(w1, w2);
            swap(n, m);  // Swap sizes too
        }

        // Two-pointer approach to match from the start and end
        int l = 0, r = n - 1;
        int i = 0, j = m - 1;

        // Match words from the beginning
        while (l < n && i < m && w1[l] == w2[i]) {
            i++;
            l++;
        }
        
        // Match words from the end
        while (j >= i && w1[r] == w2[j]) {
            r--;
            j--;
        }

        // If j < i, sentence2 fits into sentence1 with similar structure
        return j < i;
    }
};
