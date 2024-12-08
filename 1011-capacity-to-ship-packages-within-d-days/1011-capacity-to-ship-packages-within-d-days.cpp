class Solution {
public:
    int n;
    int func(vector<int>& wt, int cap){
        long long daysReq=1;
        int load=0;

        for(int i=0;i<n;i++){
            if(load+wt[i]>cap){
                daysReq++;
                load=wt[i];
            }else{
                load+=wt[i];
            }
        }
        return daysReq;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        int maxi=*max_element(wt.begin(),wt.end());
        int sum=0;
        n=wt.size();
        for(auto i:wt) sum+=i;
        
        int low=maxi,high=sum;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(wt,mid)<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return low;
    }
};