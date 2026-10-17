class Solution {
public:
    static bool digitSumComparator(int a, int b){

        int digiSumA=0,digiSumB=0;
        int A=a, B=b;
        while(a>0){
            digiSumA+= a%10;
            a/=10;
        }
        while(b>0){
            digiSumB+= b%10;
            b/=10;
        }

        return digiSumA != digiSumB ? digiSumA < digiSumB : A < B;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> afterSort = nums;

        sort(afterSort.begin() , afterSort.end(), digitSumComparator);
        //  0  1  2  3
        // [18,43,34,16]

        // [16,34,43,18]
        // num, ind 
        unordered_map<int, int> positionMap;
        int swaps=0;

        for(int i=0;i<nums.size();i++){
            positionMap[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int expectedVal=afterSort[i]; 
            int currVal=nums[i];
            if(currVal!=expectedVal){
                int idx=positionMap[expectedVal]; 
                swaps++;
                nums[i]=expectedVal; 
                nums[idx]=currVal; 
                positionMap[expectedVal] = i;
                positionMap[currVal] = idx;
            }
        }

        return swaps;

    }
};