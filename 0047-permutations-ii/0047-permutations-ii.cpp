class Solution {
public:

    void func(int i,vector<int>&arr,vector<int>&ds,vector<int> &vis,vector<vector<int>> &ans,int n){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        if(i>=n) return;

        for(int a=0;a<n;a++){


            // missed the !vis[a-1]
            /*
            !vis[a-1]: This condition ensures that the previous element arr[a-1] has not been used in the current recursive call. If the previous element hasn't been used (i.e., vis[a-1] == 0), it means we already considered the permutations that start with arr[a-1], so starting with arr[a] would create a duplicate permutation.
            */
            if(a>0 && arr[a]==arr[a-1] && !vis[a-1]) continue;
            if(!vis[a]){
                vis[a]=1;
                ds.push_back(arr[a]);
                func(a,arr,ds,vis,ans,n);
                ds.pop_back();
                vis[a]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        sort(begin(arr),end(arr));
        vector<vector<int>> ans;
        vector<int>ds;
        int n=arr.size();
        vector<int> vis(n,0);
        func(0,arr,ds,vis,ans,n);
        return ans;
    }
};