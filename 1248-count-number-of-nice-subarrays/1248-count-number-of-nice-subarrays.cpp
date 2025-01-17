class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int n=nums.size(),sum=0,count=0,oddCount=0;

        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) oddCount++;

            if(mpp.find(oddCount-k)!=mpp.end()){
                count+=mpp[oddCount-k];
            }
            mpp[oddCount]++;
        }
        return count;
    }
};