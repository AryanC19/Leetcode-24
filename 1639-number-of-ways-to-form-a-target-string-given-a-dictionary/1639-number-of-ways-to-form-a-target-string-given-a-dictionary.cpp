class Solution {
public:
    int m;//target 
    int k;//words
    const int MOD=1e9+7;
    int dp[1001][1001];

    int func(int i,int j, string &target,vector<vector<long long> > &freq){


        if(i==m) return 1;
        if(j==k) return 0;


        if(dp[i][j]!=-1) return dp[i][j];

        int nottake=func(i,j+1,target,freq) %MOD;

        int take=(freq[target[i]-'a'][j]* func(i+1,j+1,target,freq) )%MOD ;

        return dp[i][j]=(take+nottake)%MOD;

    }
    int numWays(vector<string>& words, string target) {
        
        m=target.size();
        k=words[0].size();

        memset(dp,-1,sizeof(dp));

        vector<vector<long long>> freq(26, vector<long long> (k,0));


        for(int col=0;col<k;col++){

            for(auto &word: words){
                char ch=word[col];
                freq[ch-'a'][col]++;
            }
        }

        return func(0,0,target,freq);

    }
};