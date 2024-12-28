class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int i=0;
        int n=num.size();

        if(k>=n) return "0";

        
        while(i<n){
            int a=num[i]-'0';

            while(!st.empty() && st.top() >  a && k>0){
                st.pop();
                k--;
            }
            st.push(a);
            i++;
        }

        string ans="";

    
        while(k>0){
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            ans+='0'+st.top();
            st.pop();
        }

        while(ans.size() >0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(begin(ans),end(ans));


        return ans=="" ? "0" : ans;
    }
};