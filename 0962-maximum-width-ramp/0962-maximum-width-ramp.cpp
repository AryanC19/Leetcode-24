class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;

        int n=nums.size();

        for(int i=0;i<n;i++){

            if(st.empty() || nums[st.top()] >=nums[i]){
                st.push(i);
            }
        }

        int j=n-1;

        int ramp=0;

        while(j>=0){

            while(!st.empty() && (nums[st.top()] <=nums[j])){
                int i=st.top();
                ramp=max(ramp,j-i);
                st.pop();
            }
            j--;
        }
        return ramp;
    }
};