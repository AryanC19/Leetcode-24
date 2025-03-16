class Solution {
public:

    bool valid(int cap,vector<int>& nums, int k){

        int houses=0;
        int n=nums.size();

        int i=0;
        while(i<n){
            if(nums[i]<=cap){
                houses++;
                i+=2;
            }else{
                i++;
            }
            if(houses>=k) return true;
        }
        return false;
        
    }

    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();

        int l= *min_element(nums.begin(),nums.end());

        int h= *max_element(nums.begin(),nums.end());


        int ans=h;

        while(l<=h){
            int m=l+ (h-l)/2;
            if(valid(m,nums,k)){
                h=m-1;
                ans=m;
            }else{
                l=m+1;
            }
        }

        return ans;




    }
};