class Solution {

    int[][] dp;
    public int func(int i , int[] prices, int canBuy){
        if(i>=prices.length) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];

        int buyMax=0, sellMax=0;
        /*
        at each day we are either holding a stock or free to buy.
        from each state we have two choices: take action or skip.
        if canBuy = 1:
            buy  -> -prices[i] + func(i+1, 0)
            skip -> func(i+1, 1)
        if canBuy = 0:
            sell -> +prices[i] + func(i+1, 1)
            skip -> func(i+1, 0)
        we take the max of the two options.
        */

        if(canBuy==1){
            int buy=-prices[i]+func(i+1,prices, 0);
            int dontBuy=func(i+1, prices, 1);
            buyMax=Math.max(buy,dontBuy);
        }else{
            int sell=prices[i]+func(i+1,prices, 1);
            int dontSell=func(i+1,prices, 0);
            sellMax=Math.max(sell,dontSell);
        }
        return dp[i][canBuy]=Math.max(buyMax, sellMax);
    }
    public int maxProfit(int[] prices) {
        int n=prices.length;
        // dp array initialization
        dp=new int[n+1][2];
        for(int i=0;i<dp.length;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
        return func(0,prices,1);
    }
}