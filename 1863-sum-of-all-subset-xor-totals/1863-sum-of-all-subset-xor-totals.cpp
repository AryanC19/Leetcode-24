class Solution {
public:

    int n;

    int func(int i,int currXOR, vector<int>& nums){
        if(i>=n) return currXOR;
        int take =  func(i+1,currXOR^nums[i] ,nums);
        int nottake = func(i+1,currXOR,nums);
        return take+nottake;
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size()==0) return 0;
        n=nums.size();
        return func(0,0,nums);

    }
};