class Solution {
public:


    int maxScoreSightseeingPair(vector<int>& values) {
        

        int n=values.size();

        
  //  (values[i] +i) + (values[j] - j)
    // calc a prefix map of v[i]+i

        int maxI=-1e9;
        int ans=-1e9;

        for(int i=0;i<n;i++){
            int score= maxI +values[i]-i;
            ans=max(ans,score);
            maxI=max(maxI, i+values[i]);
        }
        return ans;

    }
};