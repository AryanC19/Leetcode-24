class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == INT_MIN) 
        /*
        mother of edge cases

        INT_MIN = -2147483648 
        cannot convert to +ve because int range is [-2147483648,2147483647]

        else will overflow. 

        to fix it we do ,
        1) add +1 
        -2147483648 +1 = -2147483647
        2) now that its in range , convert to +ve
         -(-2147483647) = 2147483647 
        3) now that we have the numebr , and we took 1 away from its absolute value instead of adding it back , multiple it outside. 
        
        
readding the +1            converting to +ve       removing 1 from its abs val (n is -ve)
      x *                   myPow(x, (x,             -(n+1)))

       x *myPow(x, (x,-(n+1)))
        */
            return 1.0 / (x * myPow(x, -(n + 1))); // ✅ Fixed: added 'x'
        if (n < 0) 
            return 1.0 / myPow(x, -n); // ✅ Fixed: used '-n'
        double half = myPow(x, n / 2);
        double res = half * half;
        if (n % 2 != 0) res *= x;
        return res;
    }
};