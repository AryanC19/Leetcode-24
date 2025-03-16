class Solution {
public:
    typedef unsigned long long ll;

    ll validCars(ll cars,ll rank, ll time){

        ll l=0;
        ll h=cars;
        ll carsRepaired=0;
        while(l<=h){
            ll m= l+(h-l)/2;
            ll repairTime= rank * m * m;
            if(repairTime <=time){
                carsRepaired=m;
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return carsRepaired;
    }


    bool validTime(ll time,vector<int>& ranks, ll cars){

        ll carsRepaired=0;
        for(ll rank:ranks){
            carsRepaired+= validCars(cars, rank,time);
            if(carsRepaired>=cars) return true;
        }
        return false;
        
    }


    long long repairCars(vector<int>& ranks, int cars) {
        
        
        ll l=1;
        ll h=(ll)cars*(ll)cars* *max_element(ranks.begin(),ranks.end());
        ll ans=h;

        while(l<=h){    

            ll m=l+(h-l)/2;

            if(validTime(m,ranks,cars)){
                h=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }

        return ans;
    }
};