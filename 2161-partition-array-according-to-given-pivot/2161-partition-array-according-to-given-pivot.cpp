class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low,high;
        int cnt=0;

        for(auto i:nums){
            if(i<pivot) low.push_back(i);
            else if(i>pivot) high.push_back(i);
            else cnt++;
        }
        while(cnt--) low.push_back(pivot);
        for(auto i:high) low.push_back(i);
        return low;
    }
};