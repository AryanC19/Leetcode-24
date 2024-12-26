class Solution {
public:

    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;

        vector<int> circular;

        int n=nums.size();

        for(auto i:nums) circular.push_back(i);
        for(auto i:nums) circular.push_back(i);

        
        vector<int> nge(n);


        for(int i=2*(n-1);i>=0;i--){

            


            while(!st.empty() && circular[i]>= st.top()){
                st.pop();
            }

            if(i<n)
                nge[i]= st.empty() ? -1 : st.top();

            st.push(circular[i]);
        }

        return nge;


    }
};