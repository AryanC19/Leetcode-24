class Solution {
public:
    typedef long long ll;
    bool func(ll speed, vector<int>& piles, ll limit){
        ll hours=0;
        for(auto &i:piles){
            hours+= ceil(double(i)/double(speed));
            if(hours>limit) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int k) {
        
        int n=piles.size();
        ll l=1;
        ll h=*max_element(piles.begin(),piles.end());
        ll ans=1e9;
        while(l<=h){

            ll m=l+(h-l)/2;

            if(func(m,piles,k)){
                h=m-1;
                ans=min(ans,m);
            }else{
                l=m+1;
            }
        }
        return ans;

    }
};