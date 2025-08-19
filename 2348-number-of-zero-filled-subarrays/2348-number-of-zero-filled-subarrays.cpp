class Solution {
public:
typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        

        ll zC=0;

        int n=nums.size();
        ll ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) {
                zC++;
                ans+= zC;
            }
            else{
                
                zC=0;
            }
        }
        return ans;
    }
};