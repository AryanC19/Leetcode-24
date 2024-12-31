class Solution {
public:

    int n;
    int dp[366];
    int func(int i,vector<int>& days, vector<int>& costs){

        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        //1-day
        int j=i;

        int one_day=costs[0]+func(i+1,days,costs);
        //7-day

        j=i;
        while(j<n && days[j]<=days[i]+6) j++;
        
        int seven_day=costs[1]+func(j,days,costs);
        //30-day
        j=i;
        while(j<n && days[j]<=days[i]+29) j++;

        int thirty_day=costs[2]+func(j,days,costs);

        return dp[i] = min({one_day,seven_day,thirty_day});

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        memset(dp,-1,sizeof(dp));
        return func(0,days,costs);

    }
};