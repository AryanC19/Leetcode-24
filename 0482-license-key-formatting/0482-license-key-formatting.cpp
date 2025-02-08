class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        

        stringstream ss(s);
        string token="";
        vector<string> words;

        while(getline(ss,token,'-')){
            words.push_back(token);
        }

        for(int i=0;i<words.size();i++){
            for(char &c:words[i]){
                if(isalpha(c)){
                    if(islower(c)) c=toupper(c);
                }
            }
        }

        string ans="";
        

        // {5f3z,2e,9,w}
        //           i

        int cnt=0;
        for(int i=words.size()-1;i>=0;i--){
            for(int j=words[i].size()-1;j>=0;j--){
                ans+=words[i][j];
                cnt++;
                if(cnt==k){
                    //cout<<ans<<endl;
                    ans+='-';
                    cnt=0;
                }
            }
        }
        if(!ans.empty() && ans[ans.size()-1]=='-')
            ans.pop_back();
        //cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;

    }
};