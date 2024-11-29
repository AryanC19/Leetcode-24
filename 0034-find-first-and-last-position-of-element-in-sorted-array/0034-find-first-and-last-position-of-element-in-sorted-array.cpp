class Solution {
public:
    int n;

    // Upper Bound Function
    int ub(vector<int>& arr, int target){
        int ans = -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] > target){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (ans == -1) ? n : ans;
    }

    // Lower Bound Function
    int lb(vector<int>& arr, int target){
        int ans = -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        n = arr.size();

        // Finding lower bound
        int lower = lb(arr, target);
        if(lower == -1 || arr[lower] != target) return {-1, -1};

        // Finding upper bound
        int upper = ub(arr, target);

        // Return the correct range
        return {lower, upper - 1};
    }
};
