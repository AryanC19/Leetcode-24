class Solution {
public:
   int N,P,m;
   const int MOD=1e9+7;

   int dp[101][101][101];
   int func(int i,int members,int curr_profit, vector<int>& group, vector<int>& profit){
    curr_profit = min(curr_profit, P); // Key fix
       if(i>=m){
           if(curr_profit>=P && members<=N) return 1;
           return 0;
       }

       if(members>N) return 0;
    
        if(dp[i][members][curr_profit]!=-1) return dp[i][members][curr_profit];
       int notpick=func(i+1,members,curr_profit,group,profit);
       int pick=0;
       if(members+group[i]<=N){
           pick=func(i+1,members+group[i],curr_profit+profit[i],group,profit);
       }
       return dp[i][members][curr_profit]=(pick+notpick)%MOD;
   }
   int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
       N=n;
       P=minProfit;
       m=group.size();
       memset(dp,-1,sizeof(dp));
       return func(0,0,0,group,profit);
   }
};