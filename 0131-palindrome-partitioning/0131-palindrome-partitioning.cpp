class Solution {
public:
    bool isPali(string &s,int i,int j){
        int n=s.size();
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }


    void func(int idx,string &s,vector<string> &curr,vector<vector<string>> &ans){
        int n=s.size();
        if(idx>=n){
            ans.push_back(curr);
            return;
        }


        for(int i=idx;i<n;i++){

            if(isPali(s,idx,i)){

                curr.push_back(s.substr(idx,i-idx+1));
                func(i+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        vector<vector<string> > ans;
        vector<string> curr;
        func(0,s,curr,ans);
        return ans;

    }
};