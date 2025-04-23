class Solution {
public:
    int countLargestGroup(int n) {
        
        unordered_map<int,int> mpp;
        int maxSize=INT_MIN;
        for(int i=1;i<=n;i++){

            string s= to_string(i);
            int sum=0;

            for(auto j: s) sum+= j-'0';

            mpp[sum]++;
            maxSize=max(maxSize,mpp[sum]);
        }

        int ans=0;
        for(auto it:mpp){
            if(it.second==maxSize) ans++;
        }
        return ans;
    }
};