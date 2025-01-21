class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {    
    
    
        int xor1=0,xor2=0;

        for(auto i:nums1) xor1^=i;
        for(auto i:nums2) xor2^=i;

        int n=nums1.size();
        int m=nums2.size();


        if(n%2==0 && m%2==0){
            return 0;
        }else if(n%2==0 && m%2!=0){
            return xor1;
        }else if(n%2!=0 && m%2==0){
            return xor2;
        }else{
            return xor1^xor2;
        }
    }
};