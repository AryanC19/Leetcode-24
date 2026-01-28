class Solution {
public:
/*
[3,6,7,11] k=4
 1 2 2 3 =8h
*/

    bool canEat(int bananasPerHour,vector<int>& piles, int maxAllowedHours){
        int hours=0;
        for(int &bananas: piles){
            // ceil , 4%3 -> rem of 4/3
            if(bananas % bananasPerHour !=0){
                hours+= (bananas/bananasPerHour)+1;
            }else{
                hours+=(bananas/bananasPerHour);
            }
            if(hours>maxAllowedHours) return false;
        }
        return hours<=maxAllowedHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int minBananas=1;
        int maxBananas=*max_element(piles.begin(),piles.end());

        // for(int bananas=minBananas;bananas<=maxBananas;bananas++){
        //     if(canEat(bananas, piles, h)) return bananas;
        // }

        int l=minBananas;
        int r=maxBananas;

        int minSpeed=0;
        while(l<=r){
            int m= l+(r-l)/2;

            if(canEat(m,piles,h)){
                r=m-1;
                minSpeed=m;
            }else{
                l=m+1;
            }
        }

        return minSpeed;
    }
};