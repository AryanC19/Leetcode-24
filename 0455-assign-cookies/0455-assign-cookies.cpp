class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& size) {
        sort(begin(greed),end(greed));
        sort(begin(size),end(size));
        int n=greed.size(),m=size.size();
        int i=0,j=0;
        int ans=0;

        while(i<n && j<m){
            if(size[j]>=greed[i]){
                i++;
                j++;
                ans++;
            }else{
                j++;
            }
        }
        return ans;
    }
};