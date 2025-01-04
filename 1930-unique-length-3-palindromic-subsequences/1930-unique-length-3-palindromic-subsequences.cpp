class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int> > mpp;




        for(int i=0;i<s.size();i++){

            if(!mpp.count(s[i])){
                mpp[s[i]].first=i;
                mpp[s[i]].second=i;
            }else{
                mpp[s[i]].second=i;
            }
        }


        int ans=0;

        for(auto &it:mpp){

            char c=it.first;
            int fO=it.second.first;
            int lO=it.second.second;

            if(fO==lO) continue;
            // WRONG
            // if(!st.count(c)){
            //     st.insert(c);
            //     ans+= lO-fO;
            // }

            // Count unique characters between first and last occurrence
            unordered_set<char> uniqueMiddle;
                                    //i ___ j 
                    // i+1 to j-1  // a b c d 
            for(int i = fO + 1; i < lO; i++) {
                uniqueMiddle.insert(s[i]);
            }
            ans += uniqueMiddle.size();
        }


        return ans;
    }
};