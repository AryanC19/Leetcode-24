class Solution {
public:
    long long coloredCells(int n) {
        int d=4;
        long long ans=1;
        n--;

        while(n--){
            ans+=d;
            d+=4;
        }
        return ans;
    }
};