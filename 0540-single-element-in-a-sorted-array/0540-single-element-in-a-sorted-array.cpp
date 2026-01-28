class Solution {
public:
/*
hashmap -> tc O 2n , sc O n

bs:
    0 1 2 3 4 5 6 7 8
    1,1,2,3,3,4,4,8,8
    before single el : odd even
    after single el : even odd
    at single, arr[i-1]!=arr[i] && arr[i] != arr[i+1];

*/
    int singleNonDuplicate(vector<int>& arr) {
        
        int n=arr.size();

        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
    
        int low=1;
        int high=n-2;
//NEED <=, regardless of odd or even 

/*
    12345
     lr 
     situation can arise. 
*/
        while(low<=high){

            int mid=low+ (high-low)/2;
            cout << mid<<endl;
            if(arr[mid-1]!= arr[mid] && arr[mid]!=arr[mid+1]) return arr[mid];
            // if pair is mid,mid+1 OR mid-1,mid. have to check FIRST idx of pair
            if(arr[mid]==arr[mid+1]){
                //before single el, 
                if(mid % 2 ==0){
                    low=mid+1;
                }//after
                else{
                    high=mid-1;
                }
            }else{ // arr[mid]== arr[mid-1]
                if((mid-1)%2==0){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }

        return -1;
    }
};