class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
// write your code here
		int n=nums.size();
        sort(nums.begin(), nums.end());

		vector<vector<int> > ans;

		int target=0;
        

		//sorted
		for(int i=0;i<n;i++){
		    
		    int j=i+1,k=n-1;
            
		    if(i>0 && nums[i-1]==nums[i]) continue;
		    while(j<k){
		        
		        long long sum=0;
		        sum+=nums[i];
		        sum+=nums[j];
		        sum+=nums[k];
		        
		        if(sum==target){
                    
		            ans.push_back({nums[i],nums[j],nums[k]} );
                    j++;
                    k--;
		            while(j<k && nums[j]==nums[j-1]) j++;
		            while(j<k && nums[k]==nums[k+1]) k--;
		        }else if(sum>target){
		            k--;
		        }else{
		            j++;
		        }
		    }
		}
		return ans;
    }
};