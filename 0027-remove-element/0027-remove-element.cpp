class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0) return 0;
       // if(n == 1) return nums[0] == val ? 0 : 1;
        
        int i = 0;
        int j = n - 1;
        
        while(i <= j) {
            while(i <= j && nums[i] != val) {
                i++;
            }
            while(i <= j && nums[j] == val) {
                j--;
            }
            
            if(i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        
        return i;
    }
};