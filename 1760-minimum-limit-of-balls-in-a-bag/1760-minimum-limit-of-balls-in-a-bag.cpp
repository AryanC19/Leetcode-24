class Solution {
public:

// minimize maximum --> binary search

    bool valid(int split,vector<int>& nums, int maxOp){

        

        int op=0;

        for(auto i:nums){
            // while(i>split){
            //     op++;
            //     i-=split;
            // }
            
            
            op+=(i-1)/split;
            
            if(op>maxOp) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();

        int l=1,h=*max_element(begin(nums),end(nums));
        int ans=INT_MAX;
        while(l<=h){
            int m=l+(h-l)/2;
            if(valid(m,nums,maxOperations)){ 
                ans=min(ans,m);
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;

    }
};