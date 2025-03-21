class Solution {
public:
    string smallestNumber(string pattern) {
        

        stack<char> st;
        string ans="";

        for(int i=0;i<=pattern.size();i++){
            st.push(i+'1');
            
            if(i==pattern.size() || pattern[i]=='I'){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
            }
        }
    
        return ans;
    }
};