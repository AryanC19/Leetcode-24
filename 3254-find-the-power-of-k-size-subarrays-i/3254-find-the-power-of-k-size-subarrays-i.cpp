class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int cnt=1;
        int n=nums.size();
        vector<int> res(n-k+1,-1);


        //preprocess first win
        for(int i=1;i<k;i++){

            if(nums[i-1]+1==nums[i]) cnt++;
            else cnt=1;
        }
        if(cnt==k) res[0]=nums[k-1];


        int i=1,j=k;


        while(j<n){

           if(nums[j-1]+1==nums[j]) cnt++;
            else cnt=1;

            if(cnt>=k) res[i] =nums[j];


            i++;j++;
        }

        return res;
    }
};