class Solution {
public:
    bool divideArray(vector<int>& nums) {
       int n=nums.size();
       int N=n/2;


        unordered_map<int,int> mpp;

        for(auto i :nums){
            mpp[i]++;
        }
        int pair=0;

        for(auto it:mpp){

            if(it.second%2!=0) return false;
            else{
                pair+= it.second/2;
            }
        }

        return pair>=N;

    }
};