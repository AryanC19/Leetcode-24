class Solution {
public:
    typedef long long ll;

    long long countSubarrays(vector<int>& nums, int k) {
        ll ans=0;
        ll maxE= *max_element(nums.begin(),nums.end());
        int n=nums.size();

        int l=0;
        int r=0;

        int cnt=0;


        while(r<n){

            cnt+= nums[r]==maxE? 1:0;

            while(cnt>=k){

                cnt-= nums[l]==maxE?1:0;
                ans+=n-r;
                l++;
            }
            r++;
        }
        return ans;
        
    }
};