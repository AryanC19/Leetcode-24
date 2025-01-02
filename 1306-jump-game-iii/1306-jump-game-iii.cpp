class Solution {
public:
    int n;
    
    bool func(int i,vector<int>& arr,vector<int> &vis){

        if(i>=n || i<0 || vis[i]==1) return false;
        if(arr[i]==0) return true;
        vis[i]=1;
        bool front= func(i+arr[i],arr,vis);
        bool back=func(i-arr[i],arr,vis);


        return front|back;
    }
    bool canReach(vector<int>& arr, int start) {

        n=arr.size();
        vector<int> vis(n,0);
        return func(start,arr,vis);
    }
};