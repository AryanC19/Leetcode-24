class Solution {
public:

    void mergeFunc(vector<int> &nums, int l, int m , int r){
        
        int s1= m-l+1;
        int s2= r-(m+1)+1;
        

        vector<int> arr1(s1), arr2(s2);

        for(int i=0;i<s1;i++){
            arr1[i]=nums[l+i];
        }


        for(int i=0;i<s2;i++){
            arr2[i]=nums[m+1+i];
        }

        int k=l;
        int i=0,j=0;
        while(i<s1 && j<s2){
            if(arr1[i] < arr2[j]){
                nums[k++]=arr1[i++];
            }else{
                nums[k++]=arr2[j++];
            }
        }

        while(i<s1){
           
            nums[k++]=arr1[i++];
            
        }


        while( j<s2){
            nums[k++]=arr2[j++];
            
        }

    }
    void mergeSort(vector<int> &nums, int l, int r){

        if(l>=r) return;
        int m= l+(r-l)/2;

        mergeSort(nums,l,m );
        mergeSort(nums,m+1, r);
        mergeFunc(nums, l, m , r);

    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums, 0, n-1);
    }
};