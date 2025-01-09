class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        auto comp = [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];  // Simply compare units per box directly
        };
        sort(begin(boxTypes), end(boxTypes), comp);
        int maxUnits = 0;
        
        for(auto &box : boxTypes){
            int boxesToTake = min(box[0], truckSize);  // Take minimum of available boxes and remaining space
            maxUnits += boxesToTake * box[1];          // multiply boxes taken by units per box
            truckSize -= boxesToTake;
            if(truckSize == 0) break;
        }
        return maxUnits;
    }
};