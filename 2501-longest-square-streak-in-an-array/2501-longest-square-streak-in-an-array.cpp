class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<double ,double> mpp;
        int ans=0;
        // 2,3,4,6,8,16
        sort(begin(nums),end(nums));
        for(auto i:nums){
            if(mpp.find(sqrt(i))!=mpp.end()){
                //cout<<i<< " "<< sqrt(i)<<endl;
                mpp[i]=mpp[sqrt(i)]+1;
                
                if(ans <mpp[i]) ans=mpp[i];
            }else{
                mpp[i]=1;
            }
        }

        // for(auto i:mpp){

        //     cout<<i.first<< " "<<i.second<<endl;
        // }
        return ans<2 ?-1 : ans;
    }
};