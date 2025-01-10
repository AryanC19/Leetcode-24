class Solution {
public:
    int returnIndex(string word,string pref){
        int i=0;
        int j=0;
        sort(begin(word),end(word));
        sort(begin(pref),end(pref));

       // cout<<word<< " "<<pref<<endl;
        int n=word.size();
        int m=pref.size();

        for(i=0;i<n;i++){
            int j=i;
            int k=0;
            while(j<n &&k<m){
                if(word[j]!=pref[k]){ 
                    j++;
                }
                else{j++;k++;}
            }
            if(k==m) return i;
        }
        return -1;

    }
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        

        vector<string> ans;

        for(auto &i :w1){

            bool flag=true;

            for(auto &j:w2){

                if(returnIndex(i,j)==-1){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;

    }
};