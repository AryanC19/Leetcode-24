class Solution {
public:
    int getsum(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        
        int maxSum=INT_MIN;
        //            sumdigi,num
        unordered_map<int,int> mpp;
        sort(nums.begin(),nums.end());

        for(auto &i:nums){
            int sum=getsum(i);
            if(mpp.count(sum)){
                maxSum=max(maxSum, i+ mpp[sum]);
            }
            mpp[sum]=i;
        }
        return maxSum==INT_MIN ?-1:maxSum;
    }
};