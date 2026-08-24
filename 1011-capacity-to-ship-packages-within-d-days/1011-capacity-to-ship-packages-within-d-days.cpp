class Solution {
public:
    bool canShip(int validCap, vector<int>& weights, int days){
        int currDays=1;
        int currWeight=0;
        for(int &w: weights){
            currWeight+=w;
            if(currWeight>validCap){
                currWeight=w;
                currDays++;
            }
            if(currDays>days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxWeight = *max_element(weights.begin(), weights.end());

        for(auto w: weights) sum+=w;

        int l=maxWeight;
        int r=sum;
        int ans=r;
        while(l<=r){

            int m=l+(r-l)/2;
            if(canShip(m,weights,days)){
                ans=min(ans, m);
                r=m-1;
            }else{
                l=m+1;
            }
        }

        return ans;
    }
};