class Solution {
public:
    //selection sort O n^2
    void sortColors(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++){
            int mini=i;
            for(int j=i+1;j<arr.size();j++){
                if(arr[mini]>arr[j]){
                    mini=j;
                }
            }
            swap(arr[mini],arr[i]);

        }
        
    }
};