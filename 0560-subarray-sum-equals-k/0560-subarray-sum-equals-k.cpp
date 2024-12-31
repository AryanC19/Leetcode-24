class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //           presum,freq of it occuring
        unordered_map<int,int> mpp;
        int ans=0,presum=0;
        int n =nums.size();
        // so that we account for the case of presum=0 has an occurence of 1
        mpp[0]=1;
        for(int i=0;i<n;i++){
            
            presum+=nums[i];

            // if ps-k present, that means we have a subar of size K between 
            // psA and ps B

            /*
            psA    
            --------->
                k
                <---->
            --->
            psB

            that means psA-psB=K
            so the subarr with size K is present so increase count

            map condition=  if (psA-k)!=mpp.end();  that is if theres an entry

            psA-psB=K
            psA-K=psB
            
            */
            if(mpp.find(presum-k)!=mpp.end()){
                ans+=mpp[presum-k];
            }   
            mpp[presum]++;
        }
        return ans;
    }
};