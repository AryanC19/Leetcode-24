class Solution {
public:
    unordered_set<string> st;
    int n;
    
    void func(int i,string &s,vector<string> &ans,string &ds){

        if(i>=n && !st.count(ds)){
            st.insert(ds);
            ans.push_back(ds);
            return;
        }

        if(isalpha(s[i])){
            ds+=toupper(s[i]);
            func(i+1,s,ans,ds);
            ds.pop_back();

            ds+=tolower(s[i]);
            func(i+1,s,ans,ds);
            ds.pop_back();

        }else{
            ds+=s[i];
            func(i+1,s,ans,ds);
            ds.pop_back();

        }
    }
    vector<string> letterCasePermutation(string s) {
        n=s.size();
        vector<string> ans;
        string ds="";
        func(0,s,ans,ds);

        return ans;
    }
};