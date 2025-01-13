class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mpp;
        for(auto i:hand) mpp[i]++;

        for(auto [h,freq] : mpp){
            if(freq==0) continue;
            while(freq--){
                for(int i=h;i<h+groupSize;i++){
                    if(mpp[i]==0) return false;
                    mpp[i]--;
                }
            }
        }
        return true;
    }
};