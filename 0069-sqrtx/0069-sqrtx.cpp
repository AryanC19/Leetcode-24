class Solution {
public:
    int mySqrt(int x) {
        

        int l=0,h=x;

        if (x == 0) return 0;

        long long ans=0;

        while(l<=h){

            long long m=l+ (h-l)/2;
            long long sqr=m*m;

            if(sqr==x) return m;

            if(sqr>x){
                h=m-1;
            }else{
                ans=m;
                l=m+1;
            }
        }
        return ans;
    }
};