class Solution {
public:
    typedef long long ll;

    long long calculateScore(string s) {
        
        ll score=0;
        int n=s.size();

        vector<int> vis(n,0);
                     //ch ind
        unordered_map<char,vector<int > > indMap;

        for(int i=0;i<n;i++){
            char cur=s[i];
            char mirror= 25 -(cur-'a' )+'a';
            cout<<cur<< " " << mirror<<endl;
            if( ! indMap[mirror].empty() && indMap.count(mirror) && !vis[i] && !vis[indMap[mirror].back()]){
                
                int j=indMap[mirror].back();
                indMap[mirror].pop_back();
                vis[i]=1;
                vis[j]=1;
                //      i   j , j<i
                score+= i- j;
            }

            indMap[cur].push_back(i);
        }     

        return score;

    }
};