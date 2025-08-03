class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans=0;
        int n=weight.size();

        int maxFar=-1;


        for(int i=0;i<n;i++){

            if(maxFar!=-1 && weight[i] < maxFar) {
                maxFar=-1;
                ans++;
                continue;
            }
            maxFar=max(maxFar, weight[i]);
            
        }
        return ans;
    }
};