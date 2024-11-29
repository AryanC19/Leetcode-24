class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n=arr.size();

        map<int,vector<int>> mpp;

        for(auto &i:pieces){
            mpp[i[0]]=i;
        }

        int ind=0;

        for(ind=0;ind<n;){

            if(mpp.find(arr[ind])!=mpp.end()){
                cout<<ind<<endl;
/*
in
91,4,64,78


78: [78]
4:  [4,64]
91: [91]
*/
                for(auto j:mpp[arr[ind]]){

                    if(arr[ind++]!=j) return false;
                }
            }else{
                
                 
               // cout<<arr[ind]<<endl;
                return false;
            }
        }

        return true;
    }
};