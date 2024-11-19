class Solution {
public:
    typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int l=0,r=0;
        ll sum=0;
        ll ans=INT_MIN;
        for(r=0;r<k;r++){
            mpp[nums[r]]++;
            sum+=nums[r];
        }
        r--;
        if(mpp.size()==k){
            ans=max(ans,sum);
        }

        cout<<"ans"<< ans<< "r" <<r<< "sum"<<sum<< endl;
        while(r<n){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            sum-=nums[l];
            l++;
            r++;

            if(r>= n) break;
            sum+=nums[r];
            
            
            mpp[nums[r]]++;
            if(mpp.size()==k){
                for(auto i:mpp) cout<< i.first<<" "<< i.second<<endl;
                cout<<"sum:"<<sum<<endl;
                ans=max(ans,sum);
            }
            
        }

        return ans==INT_MIN?0:ans;

    }
};