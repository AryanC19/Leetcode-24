class Solution {
public:
    vector<bool> arr; 

    void sieve(int n) {
        arr.resize(n + 1, true);  
        arr[0] = arr[1] = false;  

        for (int i = 2; i * i <= n; i++) {
            if (arr[i]) {
                for (int j = i * i; j <= n; j += i) { 
                    arr[j] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        sieve(right);

        vector<int> ans = {-1, -1};
        vector<int> primes;

        

        for (int i = left; i <= right; i++) {
            if (arr[i]) primes.push_back(i);
        }

        if (right == 1 || left == right || (primes.size() < 2) ) return ans;
        
        int mini = INT_MAX;
        for (int i = 0; i < primes.size() - 1; i++) {
            if (primes[i + 1] - primes[i] < mini) {
                ans = {primes[i], primes[i + 1]};
                mini = primes[i + 1] - primes[i];
            }
        }

        return ans;
    }
};
