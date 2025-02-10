class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;



        for(auto i:s){


            if(isdigit(i)){

                if(!st.empty()) st.pop();
            }else{
                st.push(i);
            }
        }

        string ans="";

        if(st.empty()) return ans;

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;

    }
};