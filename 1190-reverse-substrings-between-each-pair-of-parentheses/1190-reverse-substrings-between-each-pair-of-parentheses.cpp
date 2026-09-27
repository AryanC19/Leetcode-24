class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();

        stack<int> openBracketIdx;
        unordered_map<int,int> bracketMap;

        for(int i=0;i<n;i++){
            if(s[i]=='(') openBracketIdx.push(i);
            else if(s[i]==')'){
                int left= openBracketIdx.top();
                openBracketIdx.pop();
                int right= i;
                bracketMap[left] =right;
                bracketMap[right] =left;
            }
        }

        int i=0;
        int flag=1;
        string result;
        for(int i=0;i<n;i+=flag){
            if(s[i]==')' || s[i]=='('){
                i =bracketMap[i];
                flag*=-1;
            }else{
                result.push_back(s[i]);
            }
        }        

        return result;
    }
};