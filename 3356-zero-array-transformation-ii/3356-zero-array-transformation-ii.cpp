class Solution {
public:
    bool valid(int k,vector<int>& arr, vector<vector<int>>& queries){
        int n=arr.size();

        vector<int> diff(n,0);

        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]-=val;
            if(r+1<n) diff[r+1]+=val;
        }

        for(int i=0;i<n;i++){

            diff[i]+=(i-1 >=0) ? diff[i-1] : 0;
            if(arr[i]+diff[i] >0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& arr, vector<vector<int>>& queries) {
        int n=queries.size();

        int l=0;
        int h=n;

        int ans=INT_MAX;


        while(l<=h){

            int m=l+ (h-l)/2;

            if(valid(m,arr,queries)){
                ans=min(ans,m);
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans==INT_MAX?-1: ans;
    }
};