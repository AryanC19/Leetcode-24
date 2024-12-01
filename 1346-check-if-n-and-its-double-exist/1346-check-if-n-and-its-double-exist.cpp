class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        
        unordered_map<int,int> mpp;

        for(auto i:arr){
            mpp[i]++;
        }
        for(auto i:arr){
            if(mpp.count(i*2) ){
                if(i==0) return mpp[0]>1;
                return true;}
        }
         return false;       
    }
};