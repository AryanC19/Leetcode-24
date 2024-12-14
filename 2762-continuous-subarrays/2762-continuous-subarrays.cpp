

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int n=nums.size();
        multiset<int> st;
        int l=0,r=0;

        long long cnt=0;

        while(r<n){
            st.insert(nums[r]);
            while( abs(*st.begin()-*st.rbegin())>2 ){
                st.erase(st.find(nums[l]));
                l++; 
            }

            // to count the number of subarrays, add the length.

            /*
            no subarrays , 1 ,2 , 3
            [3]:[3]
            [3,2]: [3,2],[2]
            [3,2,1]: [1] [2,1] [3,2,1]

            therefore for each new subarrat, the number of subarrayss increases by the size of the subarrat

            */
            cnt+= (r-l+1);
            r++;

        }

        return cnt;

    }
};