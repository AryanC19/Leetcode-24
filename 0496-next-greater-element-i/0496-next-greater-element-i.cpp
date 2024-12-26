class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;

        unordered_map<int,int> nge;


        int n=nums2.size();

        for(int i=n-1;i>=0;i--){

            
            if(i==n-1){
                nge[nums2[i]]=-1;
                st.push(nums2[i]);
                continue;
            }

            while(!st.empty() && nums2[i]>= st.top()){
                st.pop();
            }

            nge[nums2[i]]= st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }


        vector<int> ans;

        for(auto i:nums1){
            ans.push_back(nge[i]);
        }
        return ans;

    }
};