class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int sum=accumulate(begin(nums),end(nums),0);

        return ceil( abs(double(goal-sum)/double(limit) ));
    }
};