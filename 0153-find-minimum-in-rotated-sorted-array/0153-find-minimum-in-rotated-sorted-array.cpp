class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();

        int l=0,h=n-1;
        int mini=1e9;

        while(l<=h){

            int m=l+(h-l)/2;
            if(nums[l]<=nums[m]){
                mini=min(mini,nums[l]);
                l=m+1;
            }else{
                mini=min(mini,nums[m]);
                h=m-1;
            }
        }
        return mini;
    }
};


/*

 l   h
   m
 0 1 2 
[3,1,2]
*/