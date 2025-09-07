class Solution {
public:

    bool canShip(int weightLimit,vector<int>& arr, int limitDays,int n){


        int days=0;
        int currWeight=0;
        int i=0;
        while(i<n){
            if(currWeight+arr[i]>weightLimit){
                currWeight=arr[i];
                days++;
            }else{
                currWeight+=arr[i];
            }
            if(days>limitDays) return false;
            i++;
        }
        //for extra currweight after traversal
        // adds extra code, just rather return numDays and compare in main func 
        // whether days<=limit
        if(currWeight>0) days++;
        if(days>limitDays) return false;
        return true;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        
        int n=arr.size();

        
        int l=*max_element(arr.begin(),arr.end());
        int h=0;
        for(auto &i:arr) h+=i;


        int minDays=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(canShip(m,arr,days,n)){
                h=m-1;
            }else{
                l=m+1;
            }
        }

        return l;
    }
};