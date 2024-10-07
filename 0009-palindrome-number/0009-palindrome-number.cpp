class Solution {
public:
    bool isPalindrome(int x) {
        
        long long num=0;

        if(x<0) return false;
        int temp=x;

        while(x){
            num=10*num+x%10;
            x/=10;
        } 
        return temp==num;
    }
};