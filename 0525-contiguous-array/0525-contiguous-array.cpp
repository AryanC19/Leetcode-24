class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mpp;

        int psum=0;

        mpp[0]=-1;
        int maxlen=0;


        for(int i=0;i<nums.size();i++){
            psum+= nums[i]==1? 1:-1 ;
            if(mpp.count(psum)){
                maxlen=max(maxlen,i-mpp[psum]);
            }else{
                mpp[psum]=i;
            }
        }
        return maxlen;
    }
};