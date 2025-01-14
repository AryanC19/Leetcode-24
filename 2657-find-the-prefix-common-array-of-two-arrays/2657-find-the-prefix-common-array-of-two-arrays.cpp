class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        

        int n=A.size();

        unordered_map<int,int> mpp;
        int cnt=0;
        vector<int> C(n);

        for(int i=0;i<n;i++){

            mpp[A[i]]++;
            if(mpp[A[i]]==2) cnt++;

            mpp[B[i]]++;
            if(mpp[B[i]]==2) cnt++;

            C[i]=cnt;
        }

        return C;
    }
};