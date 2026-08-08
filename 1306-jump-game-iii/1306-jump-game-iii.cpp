class Solution {
public:
    int dp[50001];
    bool func(int i, vector<int>& arr){

        if(i<0 || i>=arr.size() ) return false;

        if(dp[i]!=-1) return dp[i];
        
        if(arr[i]==0) return dp[i]=true;

        //visited, using dp -1,0,1 instead dp -1,1 and vis 0,1. 
        dp[i] = 0;


        bool f1= func(i+arr[i], arr);
        bool f2= func(i-arr[i], arr);

        return dp[i]= (f1 || f2);
    }
    

    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp));
        return func(start, arr);      
    }
};