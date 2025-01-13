class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        map<int,int> mpp;
        for(auto i:hand) mpp[i]++;

        for(auto [h,freq]:mpp){
            if(freq==0) continue;

            /*
                                             i=1,2,3,4,6,7,8 (keys of freqMap)
                1:1 2:2 3:2 4:1 6:1 7:1 8:1
                1:1 2:2 3:2 4:1 6:1 7:1 8:1  i=1 ,mpp[1] --> mpp[3] mpp[i]--
                1:0 2:1 3:1 4:1  " "         i=2 ,mpp[2] --> mpp[4] mpp[i]--
                1:0 2:0 3:0 4:0 6:1 7:1 8:1  i=3 ,mpp[3] --> mpp[5]
                mpp[3]==0, mpp[4]==0 contniue,
                                             i=6,mpp[6]---> mpp[8] mpp[i]--;


                return true;

            */
            while(freq--){
                for(int i=h;i<h+groupSize;i++){

                    if(mpp[i]==0) return false;
                    else mpp[i]--;
                }
            }
        }
        return true;
    }
};