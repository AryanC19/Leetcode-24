class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> prevSmallerElementIndices(n),nextSmallerElementIndices(n);
        stack<int> st1,st2;
        int MOD=1e9+7;

        for(int i=0;i<n;i++){

/*
        0  1  2  3  4
        11,81,94,43,3
nsi     -1 11 81 11
st      11 43
*/
            while(!st1.empty() && arr[i]<=arr[st1.top()]){
                st1.pop();
            }

            prevSmallerElementIndices[i]= st1.empty() ? -1 : st1.top();
            st1.push(i);

        }



        for(int i=n-1;i>=0;i--){
        // dont need specifi if(i==n-1) since stack will be empty in start and pse[i]=-1

/*
        0  1  2  3  4
        11,81,94,43,3
nsi     3  43 43 3 -1
st      3 11              
*/
            while(!st2.empty() && arr[i]<arr[st2.top()]){
                st2.pop();
            }

            nextSmallerElementIndices[i]= st2.empty() ? -1 :  st2.top();
            st2.push(i);
        }

        int ans=0;

        // confusing, revise later                           len1     len2
        // mik formula, no of subarr with min as arr[i]= i- pse[i] * nse[i]-i
       for(int i = 0; i < n; i++) {
                                    
            long long left = i - (prevSmallerElementIndices[i] == -1 ? -1 : prevSmallerElementIndices[i]);
            long long right = (nextSmallerElementIndices[i] == -1 ? n : nextSmallerElementIndices[i]) - i;
            ans = (ans + (arr[i] * left * right) % MOD) % MOD;
        }

        return ans;
    }
};