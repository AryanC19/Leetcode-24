class Solution {
public:
    typedef long long ll;

    bool valid(int same,vector<int>& candies, long long k){
        int n=candies.size();
        ll cnt=0;
        for(auto &pile : candies){
            cnt+= pile/same;
            if(cnt>=k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        
        int n=candies.size();

        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        int ans=0;

        while(l<=h){

            int m=l+ (h-l)/2;

            if(valid(m,candies,k)){
                ans=m;
                l=m+1;
            }else{
                h=m-1;
            }
        }

        return ans;

    }
};