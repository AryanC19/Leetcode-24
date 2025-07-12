class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();

        int consCnt=1;// count of consecutive elemnts

        

        vector<int> ans(n-k+1,-1);
       
        for (int i = 1; i < k; i++) {
            if(nums[i]==nums[i-1]+1) consCnt++;
            else consCnt=1;
        }


        if(consCnt==k) ans[0]=nums[k-1];

        int l=1, r=k;


        while(r<n){

            
            if(nums[r]-nums[r-1] ==1) consCnt++; 
            else consCnt=1;

        
            if(consCnt>=k){
                ans[l]=nums[r];
            }

            l++;            
            r++;
        }
        return ans;
    }
};