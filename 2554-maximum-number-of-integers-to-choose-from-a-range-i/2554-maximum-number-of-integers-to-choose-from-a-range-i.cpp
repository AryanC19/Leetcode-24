class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) {
        
        set<int> st(begin(b),end(b));
        int sum=0;
        int ans=INT_MIN;
        vector<int>arr;

        for(int i=1;i<=n;i++){
            if(!st.count(i)) arr.push_back(i);
        }
        int l=0,r=0;
        int cnt=0;
        vector<int> vis(n+1,0);
        int N=arr.size();

        while(r<N){
            if(r<N && !vis[arr[r]]){
                vis[arr[r]]=1;
                sum+=arr[r];
                cnt++;
            }

            while(sum>maxSum && l<=r){
                if(vis[arr[l]])
                    sum-=arr[l];
                l++;
                cnt--;
            }
            ans=max(ans,cnt);
            r++;
        }
        return ans==INT_MIN ?0:ans;
    }
};