class Solution {
public:
    
    vector<int> sieveOferathnoses(int n){
        vector<int> sieve(n,1);
        sieve[0]=-1;
        sieve[1]=-1;
        for(int i = 2; i * i < n; i++) {
            if(sieve[i] == 1) {
                // Start from i*i instead of i*2
                for(int j = i * i; j < n; j += i) {
                    sieve[j] = -1;
                }
            }
        }

        vector<int> pf;
        for(int i=0;i<n;i++){
            if(sieve[i]==1) pf.push_back(i);
        }
        return pf;
    }
    
    
    int findFactors(int n,vector<int> &primes){
       // vector<int> factors;
        int sum=0;
        for(auto &i:primes){
            while(n%i==0){
                n/=i;
                //factors.push_back(i);
                sum+=i;
            }

            if(n==1) break;
        }
        return sum;
        
    }
    
    int sumOfFactors(int n,vector<int> & primes){
        
        int sum=findFactors(n,primes);
        if(sum==n) return n;
        return sumOfFactors(sum,primes);
        
    }
    int smallestValue(int n) {
        
        vector<int> primes = sieveOferathnoses(n + 1);  // n + 1 to include n itself
        return sumOfFactors(n, primes);

    }
};