class Solution {
public:


/*
0   1   2  3 4  5  6  7
[73,74,75,71,69,72,76,73]
74  75 76 72 72 76 -1 -1
1   2   6  5 5 6  -1 -1 

*/
    vector<int> nge(vector<int>& arr,int n){

        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            ans[i]= st.empty() ? -1 : st.top();
            st.push(i); 
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ngeArr=nge(temperatures,n);

        vector<int> ans(n);

        for(int i=0;i<n;i++){

            ans[i]= ngeArr[i]== -1 ? 0 : ngeArr[i]-i;

        }
        return ans;
    }
};