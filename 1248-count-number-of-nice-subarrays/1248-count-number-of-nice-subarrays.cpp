class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0, r = 0, validsub = 0, ans = 0, sum = 0;

        while (r < n) {
            sum += nums[r]%2==0?0:1;

            while (sum > goal && l < r) {
                sum -= nums[l]%2==0?0:1;
                l++;
                validsub = 0;
            }

            if (sum == goal) {
                validsub = 1;
                int templ = l;
                while (templ < r && nums[templ] %2== 0) {
                    validsub++;
                    templ++;
                }
                ans += validsub;
            }
            r++;
        }

        return ans;
    }
};