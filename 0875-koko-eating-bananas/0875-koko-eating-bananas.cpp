class Solution {
public:
    /*
     1 2 2 3   
    [3,6,7,11]
    */
    bool canEat(int bananasPerHour,vector<int>& piles, int limit){
        double hours=0;
        for(int bananas:piles){
            hours+= ceil(double (bananas)/ double (bananasPerHour));
            if(hours>limit) return false;
        }
        return true;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int H) {
        
        int l=1;
        int h=*max_element(piles.begin(),piles.end());
        int ans=0;
        
        while(l<=h){
            
            int m=l+((h-l)/2);
            
            if(canEat(m,piles,H)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};