class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n=b.size();


        int l=0,r=0;
        int ans=n;
        int W=0,B=0;

        while(r<n){
            b[r]=='W' ? W++:B++;

            while(r-l+1>k){
                b[l]=='W' ? W--: B--;
                l++;
            }

            if(r-l+1==k)
                ans=min(ans,W);
            r++;
        }
        return ans;

    }
};