class Solution {
public:
typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();

        int l=0,r=0;
        ll ans=0;

        ll sum=0;

        while(r<n){

            sum+=nums[r];

            ll score= sum * (r-l+1);

            while(score>=k){
                sum-=nums[l];
                l++;
                score= sum* (r-l+1);
            }

            ans+= (r-l+1);
            
            r++;
        }

        return ans;

    }
};