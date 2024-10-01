class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;

        for(auto i:arr){
            // throws error for negative number
           // mpp[i%k]++;

            //**** very imp, modulo for negative numbers is calc as 
            //for handling negative remainders
            int mod= (i%k+k)%k;
            mpp[mod]++;
             
        }
        /*
        1:1
        2:2
        3:3
        4:4
        5:5
        6:6
        7:0
        for(i=1 to <=3) {
            
            int rem= 7-1=6;
                1       1
            if(mpp[6]==mpp[1]) 

            int rem= 7-2=5;
                1       1
            if(mpp[5]==mpp[2]) 
            .
            .
            .
        }
        */

        if(mpp[0] %2!=0) return false;

        for(int i=1;i<=k/2;i++){
            int rem=k-i;
            cout<<rem<<" "<<i<<endl;
            cout<<mpp[rem]<<" "<<mpp[i]<<endl;
            if(mpp[rem]!=mpp[i]){
                return false;
            }   
        }
        return true;
    }
};