class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(auto i:s){
            if(!st.empty() &&  i==']' && st.top() =='['){
                st.pop();
            }else{
                st.push(i);
            }
        }

        int n=st.size();
        
        return ((n/2)+1)/2;
    }
};