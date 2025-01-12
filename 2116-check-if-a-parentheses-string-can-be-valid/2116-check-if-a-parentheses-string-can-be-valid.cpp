class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        stack<int> open,variable;

        if(n%2!=0) return false;

        for(int i=0;i<n;i++){

            if(locked[i]=='0'){
                variable.push(i);
            }else{ 
                //locked=='1' (fixed)

                if(s[i]=='('){
                    open.push(i);
                }
                else if(s[i]==')'){
                    if(!open.empty()){
                        open.pop();
                    }else if(!variable.empty()){
                        variable.pop();
                    }else{
                        return false;
                    }
                }
            }
        }


        while(!open.empty() && variable.empty()){
            // first open then vaiable comes. open is locked
            if(open.top()<variable.top()){
                open.pop();
                variable.pop();
            }
        }
        return open.empty();
    }
};