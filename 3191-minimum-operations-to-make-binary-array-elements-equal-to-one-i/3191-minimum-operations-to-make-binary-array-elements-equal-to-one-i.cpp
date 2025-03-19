class Solution {
public:
    
    void flip(int ind,vector<int>& nums){
        
            for(int i=ind;i<=ind+2;i++){
                if(nums[i]==0) nums[i] =1;
                else nums[i] =0;
            }
        
    }
    int minOperations(vector<int>& nums) {
        
        
        int n=nums.size();
        int op=0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1) continue;
            else{
                
                
                op++;
                //for(auto i:nums) cout<<i <<" ";
                //cout<<endl<<i<<" ";
                if(i+2<n) flip(i,nums);
                else break;
                
                
                //cout<<endl;
            }
        }
        
        
        for(auto i:nums) if(i==0) return -1;
        
        return op;
        
    }
};