class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int n=arr.size();

        int minPrice=INT_MAX;

        int profit=0;
        for(auto price:arr){
            minPrice=min(minPrice,price);
            profit=max(profit,price-minPrice);
        }
        return profit;
    }
};