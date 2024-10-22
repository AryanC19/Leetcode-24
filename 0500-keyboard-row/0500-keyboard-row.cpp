class Solution {
public:

    bool contains(unordered_map<char,int> &mpp,string s){

        for(auto i:s){
            if(mpp.find(i)==mpp.end()) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        
        vector<string> ans;
        string s1="qwertyuiopQWERTYUIOP";
        string s2="asdfghjklASDFGHJKL";
        string s3="zxcvbnmZXCVBNM";
        unordered_map<char,int> mpp1,mpp2,mpp3;
        for(auto i:s1) mpp1[i]++;
        for(auto i:s2) mpp2[i]++;
        for(auto i:s3) mpp3[i]++;
        for(auto i: words){
            if(contains(mpp1,i) || contains(mpp2,i) ||contains(mpp3,i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};