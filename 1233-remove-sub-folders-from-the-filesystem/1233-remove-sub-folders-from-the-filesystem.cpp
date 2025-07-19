class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        unordered_set<string> st;
        sort(folder.begin(),folder.end());
        

        for(auto &dir:folder){
            string temp="";
            bool pres=false;
            int n=dir.size();
            for(int i=0;i<n;i++){
                temp+=dir[i];
                if(st.count(temp) && (i+1<n) && dir[i+1]=='/'){
                    pres=true;
                    break;
                } 
            }
            if(!pres) {st.insert(temp);}
            temp="";
        }

        vector<string> ans;

        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};