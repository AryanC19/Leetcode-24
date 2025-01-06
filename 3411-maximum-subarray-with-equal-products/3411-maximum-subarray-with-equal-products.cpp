class Solution {
public:
    typedef unsigned long long ll;

    ll gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    ll lcm(int a,int b){
        return (a*b) /gcd(a,b);
    }


    int maxLength(vector<int>& nums) {
        
        int n=nums.size();

        int ans=0;

        for(int i=0;i<n;i++){
            
            ll prod=1;
            ll lcmArr=nums[i];
            ll gcdArr=nums[i];

            for(int j=i;j<n;j++){

                prod*=nums[j];
                int b=nums[j];
                lcmArr=lcm(lcmArr,b);
                gcdArr=gcd(gcdArr,b);

                if(prod == lcmArr*gcdArr){
                    ans=max(ans,j-i+1);
                }
            }

        }

        return ans;
    }
};