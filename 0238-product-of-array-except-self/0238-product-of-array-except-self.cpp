class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        /*

        1     2      4       6
    lm  1     1     1x2    1x2x4  " "

" "    2x4x6  6x4     6       1     rm
        */

        int n=nums.size();

        vector<int> left(n,1), right(n,1);

        int preMult=1;

        for(int i=1;i<n;i++){
            preMult*=nums[i-1];
            left[i]=preMult;
        }


        preMult=1;
        for(int i=n-2;i>=0;i--){
            preMult*=nums[i+1];
            right[i]=preMult;
        }

        
        vector<int> ans(n);
        for (int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};
