class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        int ans=INT_MIN;
        int aS=0,aE=-1,S;
        for(int i=0;i<n;i++){
            if(sum==0) S=i;

            sum+=nums[i];

            if(ans<sum){
                ans=sum;
                aE=i;
                aS=S;
            }

            if(sum<0) sum=0;
        }

        for(int i=aS;i<aE;i++) cout << nums[i]<<" ";
        return ans;
    }
};