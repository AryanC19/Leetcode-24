class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        
        vector<int> arr;
        
        for(auto row:grid){

            for(int i:row) arr.push_back(i);
        }   

        sort(arr.begin(),arr.end());

        int med= arr.size()/2;

        int median=arr[med];

        int mod=median%x;

        int res=0;

        for(int i : arr){
            
            if(i%x != mod ) return -1;
            res+= (abs(i-median) / x);
        }

        return res;

    }
};