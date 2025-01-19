class Solution {
public:
    int subarraySum(vector<int>& nums) {
        
        int n=nums.size();


        int start=0;
        int ans=0;

        for(int i=0;i<n;i++){
            int sum=0;
            start=max(0,i-nums[i]);
            //cout<<"start "<<start<<endl;
            for(int j=start;j<=i;j++){
                sum+=nums[j];
            }
           // cout<<i<< " "<<nums[i]<<" "<<endl;
            ans+=sum;
            
        }

        return ans;

    }
};