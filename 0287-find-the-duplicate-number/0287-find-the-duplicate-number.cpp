class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
// doing the first iteration manually sonce out while loop base case is slow!=fast

        int slow=0, fast=0;

        slow=nums[0];
        fast=nums[nums[0]];

// runnign  the first while loop with dlow moving once and fast moving twice to check for cycle and postion fast pointer for the nect loop
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }

        // after the firs slow==fast, we reset slwo and change the moves to each moves once per pointer
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};