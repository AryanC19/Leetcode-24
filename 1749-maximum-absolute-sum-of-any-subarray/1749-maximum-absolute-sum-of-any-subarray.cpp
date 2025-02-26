class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();

        int maxi=0,mini=0;

        int sum=0;

        int ans=0;


        for(auto &i:nums){
            sum+=i;
            if(sum<0) sum=0;
            ans=max(ans,sum);
        }
        sum=0;

        int mans=0;


        for(auto &i:nums){
            sum+=i;
            if(sum>0) sum=0;
            mans=min(mans,sum);
        }

        return max( abs(ans), abs(mans));

    }
};