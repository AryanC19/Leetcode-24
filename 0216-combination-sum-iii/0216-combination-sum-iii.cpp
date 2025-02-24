class Solution {
public:
    vector<vector<int> > ans;
    typedef long long ll;

    void func(int i,vector<int> &ds, vector<int> & arr,ll n,int k){

        if(ds.size()==k && n==0){
            ans.push_back(ds);
            return;
        }
        if(k<0 ) return;
        if(i>=arr.size()) return;

        ds.push_back(arr[i]);
        func(i+1,ds,arr,n-arr[i],k);
        ds.pop_back();
        func(i+1,ds,arr,n,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> arr;
        for(int i=1;i<=9;i++){
            arr.push_back(i);
        }
        vector<int> ds;

        func(0,ds,arr,n,k);

        return ans;

    }
};