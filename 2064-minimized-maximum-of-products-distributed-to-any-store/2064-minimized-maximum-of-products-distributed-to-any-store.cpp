class Solution {
public:
    bool canBeMax(double maxi, vector<int>& arr, int n) {

        int pos = 0;
        for (int i = 0; i < arr.size(); i++) {
            double add=double (arr[i]) / maxi;
            pos += ceil (add);
        }
        

        return pos<=n;
    }
    int minimizedMaximum(int n, vector<int>& arr) {

        int low = 1;
        int high = *max_element(begin(arr), end(arr));
        int ans=INT_MAX;

        // for(int i=mini;i<=maxi;i++){
        //     if(canBeMax(i,arr,n)){
        //         ans=min(ans,i);
        //     }
        // }

        while(low<=high){
            double m= low+(high-low)/2;
            if(canBeMax(m,arr,n)){
                high=m-1;
            }else{
                low=m+1;
            }
        }

        return high+1;
    }
};