class Solution {
public:
    
    vector<int> parent;
    
    int findParent(int x){

        if(x==parent[x]) return x;

        return parent[x]=findParent(parent[x]);
    }

    void unionFunc(int x, int y){

        int x_p=findParent(x);
        int y_p=findParent(y);

        if(x_p!=y_p) parent[x_p]=y_p;

    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        parent.resize(n,0);

        for(int i=0;i<accounts.size();i++){
            parent[i]=i;
        }
        
        unordered_map<string,int> mailToNode;
        // filling nodeToMail map, and making parent
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mailToNode.count(mail)){
                    unionFunc(i,mailToNode[mail]);
                }else{
                    mailToNode[mail]=i;
                }
            }
        }
        unordered_map<int,vector<string> > mergedMailtoNode;

        for(auto i:mailToNode){

            string mail=i.first;
            int node=findParent(i.second);
            mergedMailtoNode[node].push_back(mail);

        }

        vector<vector<string> > ans;

        for(int i=0;i<mergedMailtoNode.size();i++){

            if(mergedMailtoNode[i].size()==0) continue;

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for(auto mail: mergedMailtoNode[i]){
                temp.push_back(mail);
            }
            
            sort(temp.begin(),temp.end());

            ans.push_back(temp);
        }

        return ans;
    }
};