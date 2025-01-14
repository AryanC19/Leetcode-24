class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();

        int sum=0;
        int maxsum=INT_MIN;

        int sI=0,eI=0;


        for(int i=0;i<n;i++){

            sum+=nums[i];

            if(maxsum<sum){
                maxsum=sum;
                eI=i;
            }
            
            if(sum<0){
                sum=0;
                sI=i+1;
            }
        }

        for(int i=sI;i<=eI;i++) cout<<nums[i]<<" ";
        return maxsum;
    }
};