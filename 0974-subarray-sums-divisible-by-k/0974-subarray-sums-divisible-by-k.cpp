class Solution {
public:

/*
pSa
-------->
    k             
--><----->
pSb

(pSa-pSb)%k=0;
pSa% k =psB %k

if(mpp.find(psA%k))

*/

    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;

        mpp[0]=1;
        int ans=0;
        int presum=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            if(mpp.find(presum %k)!=mpp.end()){
                ans+=mpp[presum %k];
                mpp[presum%k]++;
            }else{
                mpp[presum%k]=1;
            }
        }
        return ans;

        
    }
};