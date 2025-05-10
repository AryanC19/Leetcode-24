class Solution {
public:
    typedef long long ll; 

    long long minSum(vector<int>& nums1, vector<int>& nums2) {
     

        ll z1=0, z2=0; 

        ll s1=0,s2=0;

        for(auto i:nums1 ){

            if(i==0){
                z1++;
                s1++;
            }else{
                s1+=i;
            }
        }    


        
        for(auto i:nums2 ){

            if(i==0){
                z2++;
                s2++;
            }else{
                s2+=i;
            }
        }    

        if((s1>s2 && z2==0) || (s2>s1  && z1==0) ) return -1; 

        return max(s1,s2);
    }
};