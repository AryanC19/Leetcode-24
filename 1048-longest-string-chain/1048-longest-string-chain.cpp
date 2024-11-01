class Solution {
public:
    int n;
    vector<vector<int>> dp;
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    bool check(string &a,string &b){
        int A=a.size();
        int B=b.size();
        int size=B-A;
        if(size!=1) return false;
        else{
            int i=0,j=0;

            while(i<A && j<B){
                if(a[i]==b[j]){
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            return i==A;
        }

    }
    int func(int i,vector<string>& words,int lind){

        if(i>=n) return 0;
        if(dp[i][lind+1]!=-1) return dp[i][lind+1];

        int nottake=func(i+1,words,lind);
        int take=0;
        if(lind==-1 || check(words[lind],words[i])){
            take=1+func(i+1,words,i);
        }
        return dp[i][lind+1]=max(take,nottake);
    }
    int longestStrChain(vector<string>& words) {
        sort(begin(words),end(words),comp);
        n=words.size();
        dp.resize(n,vector<int> (n+1,-1));
        return func(0,words,-1);
    }
};