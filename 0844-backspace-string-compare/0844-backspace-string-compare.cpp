class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;


        for(auto i:s){
            if(!s1.empty() && i=='#') s1.pop();
            else s1.push(i);
        }

        for(auto i:t){
            if(!s2.empty() && i=='#') s2.pop();
            else s2.push(i);
        }


        string a="" ,b ="";

        while(!s1.empty()){
            a+=s1.top();
            s1.pop();
        }

        while(!s2.empty()){
            b+=s2.top();
            s2.pop();
        }

        return a==b;
      
    }
};