class Solution {
public:
    typedef long long ll;

    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int l=0,r=0;
        ll pairs=0;

        ll ans=0;


        int n=nums.size();

        while(r<n){

            pairs+= freq[nums[r]];// before we update the freq, so its always more than 1
            freq[nums[r]]++;

            while(l<r && pairs>=k){

                freq[nums[l]]--;
                pairs-= freq[nums[l]];
                l++; 
                ans+= (n-r);
            }
            r++;
        }

        return ans;
    }
};