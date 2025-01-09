class Solution {
public:
    int returnIndex(string &word,string&pref){

        int i=0;
        int j=0;

        int n=word.size();
        int m=pref.size();

        for(i=0;i<n;i++){
            int j=i;
            int k=0;
            while(j<n &&k<m){
                if(word[j]!=pref[k]){ break;}
                else{j++;k++;}
            }
            if(k==m) return i;
        }
        return -1;

    }
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt=0;

        for(auto &word:words){
           // if(word.find(pref)==0) cnt++;

           if(returnIndex(word,pref)==0) cnt++;
        }
        return cnt;
    }
};