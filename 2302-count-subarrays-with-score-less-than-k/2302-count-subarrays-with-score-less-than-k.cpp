class Solution {
public:
typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        unordered_map<int,ll> presum;
        int n=nums.size();
        ll psum=0;

        presum[0]=0;

        for(int i=0;i<n;i++){
            psum+=nums[i];
            presum[i+1]=psum;
        }


        int l=0,r=0;
        ll ans=0;

        ll score=0;

        while(r<n){
            score= (presum[r+1]-presum[l]) *(r-l+1);
            while( score >= k){
                l++;
                score = (presum[r+1]-presum[l]) *(r-l+1);
            }
            if(score<k) ans+= (r-l+1);
            r++;
        }

        return ans;

    }
};