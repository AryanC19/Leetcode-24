class Solution {
public:

    bool func(int k,vector<int>& piles, int th){


        int hrs=0;
        for(int i=0;i<piles.size();i++){

            //error on piles=10000000000
            // long long currhrs=ceil(float(piles[i])/float(k));
            // hrs+=currhrs;
            
            // Using integer ceiling division instead of float
            hrs += (piles[i] + k - 1) / k;  
            if(hrs>th) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int th) {
        int n=piles.size();

        long long maxi=*max_element(begin(piles),end(piles));

        long long l=1,h=maxi;

        while(l<=h){

            int m=l+(h-l)/2;

            if(func(m,piles,th)){

                h=m-1;
            }else{
                l=m+1;
            }
        }

        return l;

    }
};