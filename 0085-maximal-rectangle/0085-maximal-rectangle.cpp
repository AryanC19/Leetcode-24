class Solution {
public:

    vector<int> nse(vector<int>& arr,int n){

        stack<int> st;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i]= st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& arr,int n){
        stack<int> st;
        vector<int> ans(n);

        for(int i=0;i<n;i++){

            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        

        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        
        vector<vector<int>> levelHeight;

        vector<int> runSum(m,0);

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(matrix[i][j]=='0'){
                    runSum[j]=0;
                }else{
                    runSum[j]+=1;
                }
            }
            // for(auto &num : runSum) cout<<num<<" ";
            // cout<<endl;
            levelHeight.push_back(runSum);
        }


        for(auto &height :levelHeight){
            vector<int> psArr=pse(height,m);
            vector<int> nsArr=nse(height,m);
            for(int i=0;i<m;i++){
                int area= height[i] * (nsArr[i] - psArr[i]-1);
                ans=max(area,ans);
            }
        }

        return ans;
    }
};