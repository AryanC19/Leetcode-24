class Solution {
public:
    int mirrorDistance(int n) {
        int mirrorDist=0;

        int temp=n,revN=0;

        while(temp){
            int unitDigit=temp%10;
            revN=revN*10+unitDigit;
            temp/=10;
        }

        return abs(n-revN);
    }
};