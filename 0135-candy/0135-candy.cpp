class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> left(n,1),right(n,1),maxi(n,0);
        for(int i=1;i<n;i++){
            if(r[i-1]<r[i]){
                left[i]=left[i-1]+1;
                
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<r[i]){
                right[i]=right[i+1]+1;
            }
        }

        int i=0;
        while(i<n){
            maxi[i]=max(left[i],right[i]);
            i++;
        }

        int ans=0;
        for(auto i:maxi) ans+=i;

        return ans;
    }
};