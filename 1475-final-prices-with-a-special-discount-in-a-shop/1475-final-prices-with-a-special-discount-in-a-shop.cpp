class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        vector<int> ans;

        int n=prices.size();

        for(int i=0;i<n;i++){

            int minInd=-1;

            for(int j=i+1;j<n-1;j++){

                if(minInd==-1 && prices[j]<=prices[i]){
                    minInd=j;
                    break;
                }
            }

            if(minInd!=-1)
                prices[i]-=prices[minInd];
        }

        return prices;
    }
};