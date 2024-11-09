class Solution {
public:

    static bool comp(pair<string,int> &a,pair<string,int> &b){
        return a.second > b.second;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        unordered_map<string,int> mpp;
        vector<pair<string,int>> freq;
        unordered_set<string> bnd(begin(banned),end(banned));
        string temp="";

        for(auto i:paragraph){
            if(isalpha(i)){
                temp+=tolower(i);
            }else if( i==',' || i==' '){
                if(!temp.empty())
                    mpp[temp]++;
                temp="";
            }
        }
        mpp[temp]++;

        for(auto i:mpp){
            freq.push_back({i.first,i.second});
        }
        sort(begin(freq),end(freq),comp);


        for(auto i:freq){
            cout<<i.first<<" "<<i.second<<endl;
            if(bnd.count(i.first)==0) return i.first;
        }
        return "";

    }
};