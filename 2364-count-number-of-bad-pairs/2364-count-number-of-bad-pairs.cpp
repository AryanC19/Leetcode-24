class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        long long goodpairs=0;
        long long n=nums.size();
        long long total=n*(n-1)/2;
        //mpp[0]=0;
        for(int i=0;i<n;i++){
            int diff=i-nums[i];
            
            if(mpp.find(diff)!=mpp.end()){
                goodpairs+=mpp[diff];
            }
                mpp[diff]++;
            
        }
        return total-goodpairs;
    }   
};