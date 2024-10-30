class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        if(n == 1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;

        int l=1,h=n-2;


        while(l<=h){

            int m=l+(h-l)/2;
            if(arr[m-1]<arr[m] && arr[m]>arr[m+1]){
                return m;
            }else if(arr[m-1]<arr[m] && arr[m]<arr[m+1]){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return -1;
    }
};