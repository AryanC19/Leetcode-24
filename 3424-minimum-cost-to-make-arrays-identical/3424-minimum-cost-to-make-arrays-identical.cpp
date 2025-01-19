class Solution {
public:
    typedef long long ll;

    /*

arr    -5 -2 7
brr    -7 5 9 
    
    -1 8
    -6 4


    */
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {

        int n=arr.size();
        ll cost1=0;

        for(int i=0;i<n;i++){
            cost1+= abs(arr[i]-brr[i]);
        }

        sort(begin(arr),end(arr));
        sort(begin(brr),end(brr));
        ll cost=0;
        if(arr==brr) return cost;
        // x + brr[i]=arr[i]
        // x=arr[i]-brr[i] -5 +7 =2; -2-5=-7;7-9=-2 , 2,-7,-2  +k
        for(int i=0;i<n;i++){
            cost+= abs(arr[i]-brr[i]);
        }

        return min(cost1,cost+k);
    }
};