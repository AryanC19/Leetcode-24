class Solution {
public:
    typedef long long ll;
    int mySqrt(int x) {
        
        ll l=1;
        ll h=x;

        while(l<=h){
            int m= l+(h-l)/2;
            if(m*m > x){
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return h;
    }
};