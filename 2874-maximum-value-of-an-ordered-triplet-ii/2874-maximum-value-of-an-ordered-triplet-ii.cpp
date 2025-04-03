class Solution {
public:

    typedef long long ll;

    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();

        vector<ll> leftMax(n,0),rightMax(n,0);


        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],(ll)nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],(ll)nums[i+1]);
        }

        ll ans=0;

        for(int i=0;i<n;i++){
            ans=max(ans, (leftMax[i]-nums[i])*rightMax[i]);
        }
        return ans;

    }
};