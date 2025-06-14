class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=-1;
        int cnt=0;
        int n=nums.size();

        for(int i=0;i<n;i++){

            if(cnt==0) {
                cnt=1;
                el=nums[i];
            }

            else if(nums[i]==el) cnt++;
            else cnt--;
        
        }

        int cnt1=0;
        for(int i:nums){
            if(i==el) cnt1++;
        }

        if(cnt1>=n/2) return el;
        else return -1;
    }
};