class Solution {
public:
/*
0 1 2 3
4,3,2,1
  -1  1
-1  1
 
*/
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();

        vector<int> diffArr(n+1,0);

        for(auto &i:queries){
            int l=i[0];
            int r=i[1];
            diffArr[l]--;
            diffArr[r+1]++;
        }


        

        for(int i=1;i<n;i++){
           diffArr[i]=diffArr[i]+diffArr[i-1];
        }
        
        for(int i=0;i<n;i++){
           nums[i]+=diffArr[i];
           if(nums[i]>0) return false;
        }

        return true;
    }
};