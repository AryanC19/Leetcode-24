class Solution {
public:
    void func(int i , vector<int> &ds, vector<vector<int> > &ans,vector<int>& candidates, int target){

        if(i>=candidates.size()){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(target<0 )return;
        ds.push_back(candidates[i]);
        func(i,ds,ans, candidates,target-candidates[i]);
        ds.pop_back();
        func(i+1,ds,ans, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> ds;
        func(0,ds,ans, candidates, target);
        return ans;
    }
};