class Solution {
public:
    typedef long long ll;
    long long minimumSteps(string s) {
        ll ans=0;
        int n=s.size();
        int r=n-1;
        int l=0;

        while( r>=0 && s[r]=='1') r--;
        if(r<l) return 0;
        
        /*
        a=0  
                l             
        101010100010001
                r
        l
        012
        100
          r
        
        */
        while(l<r ){
            if(s[l]=='1'){
                ans+=r-l;
                r--;
            }
            if(r<0) break;
            while( r>=0 && s[r]=='1') r--;
            l++;
        }

        return ans;
        
    }
};