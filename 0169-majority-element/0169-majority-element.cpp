class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el = -1;

        for (auto i : nums) {
            if (cnt == 0){
                el=i;
                cnt=1;
            }
            else if (el != i) {
                cnt--;
            } else {
                cnt++;
            }
        }

        cnt=0;
        for(auto i:nums){
            if(i==el) cnt++;
        }

        if(cnt> nums.size()/2) return el;

        return -1;
    }
};