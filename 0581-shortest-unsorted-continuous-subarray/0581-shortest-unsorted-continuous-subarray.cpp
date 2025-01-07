class Solution {
public:

    int findUnsortedSubarray(vector<int>& nums) {
        int maxi=-1e9,mini=1e9;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if( (i>0  && (nums[i] < nums[i-1]) )||( i<n-1 && (nums[i] > nums[i+1]))){
                maxi=max(nums[i],maxi);
                mini=min(mini,nums[i]);
            }
        }


        int l=-1,r=-1;
                
        // 1,2,5,6,4
        for(int i=0;i<n;i++){
            if(mini<nums[i]){
                l=i;
                break;
            }
        }

        for(int j=n-1;j>=0;j--){
            if(maxi>nums[j]){
                r=j;
                break;
            }
        }

     //   cout<<maxi << " " <<mini;
        int ans=r-l+1;
        return (maxi==-1e9 || mini ==1e9) ?0 :ans;

    }
};