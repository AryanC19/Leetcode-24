class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
           | 
        1234567
        1)
        7654321
        2)
        7654321
        5674321
        */

        reverse(nums.begin(),nums.end());

        // 1234567
        // 7654321

       
        //reverse first k elmenst
        reverse(nums.begin(),nums.begin()+k);
        // ---     from begin till begin+k 
        // 7654321
        // 5674321
        


        //reveres elemts from k to end
        reverse(nums.begin()+k,nums.end());
        /*       from begin+k till end
           ----
        5674321
        5671234

        */

        
        
    }
};