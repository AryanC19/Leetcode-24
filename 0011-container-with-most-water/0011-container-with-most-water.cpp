// not understanding this mightve cost me the opportunity of a lifeitme. 
// fuckingidiot. next time understand logic better. 
// just praying to god that this didnt affect me . 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;

        int ans=0;
        int water=0;
        while(l<r ){
            ans=max(ans, min(height[l],height[r]) * (r-l));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};