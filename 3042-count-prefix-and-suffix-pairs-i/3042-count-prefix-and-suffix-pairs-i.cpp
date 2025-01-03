class Solution {
public:
    bool isPrefixAndSuffix(string &part,string &bigger){

        int n=bigger.size();
        int m=part.size();

        if(part>bigger) return false;
        
        int i=0,j=n-1;

        int k=0,l=m-1;

        while(j>=0 && k>=0 && i<n && k<m){
            if( (bigger[j--]!=part[l--])||(bigger[i++]!=part[k++])) return false;
        }
        return true;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int cnt=0;

        for(int i=0;i<words.size();i++){
            for(int j=i+1 ;j<words.size();j++){

                if(isPrefixAndSuffix (words[i],words[j])) cnt++;
            }
        }
        return cnt;
    }
};