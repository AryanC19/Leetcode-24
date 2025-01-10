class Solution {
public:

int calls=0;
    void funcOptimal(int ind, int k, vector<int>& arr, vector<vector<int>>& ans,
                     vector<int>& ds) {

        if (k == 0) {
            ans.push_back(ds);
            return;
        }
        calls++;

        if(ind==arr.size()) return ;

        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > k)
                break;
            ds.push_back(arr[i]);
            funcOptimal(i + 1, k - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {

        vector<int> ds;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        funcOptimal(0, k, arr, ans, ds);
    
        return ans;
    }
};