class Solution {
public:
    typedef long long ll;

    long long countBadPairs(vector<int>& nums) {
        ll ans=0;

        unordered_map<int,int> mpp;

        //j-nums[j] = i-nums[i];

        ll n=nums.size();

        ll bad=0;
        ll total=n* (n-1)/2;
        ll good=0;



        for(int i=0;i<nums.size();i++){

            if(mpp.count(i-nums[i]) ){
                good+=mpp[i-nums[i]];
            }
            mpp[i-nums[i]]++;
        }       

        return total-good;
    }
};