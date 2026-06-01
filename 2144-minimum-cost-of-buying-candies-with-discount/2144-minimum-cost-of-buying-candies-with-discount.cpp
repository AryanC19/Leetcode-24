class Solution {
public:

    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int n=cost.size();

        if(n==1) return cost[0];
        int money=0;

        int i=0, j=1;

        while(j<n){
            money+= cost[i]+cost[j];
            i+=3;
            j+=3;
        }
        if(i<n) money +=cost[i];

        return money;
    }
};