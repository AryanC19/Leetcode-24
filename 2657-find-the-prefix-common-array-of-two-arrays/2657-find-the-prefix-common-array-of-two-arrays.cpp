class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        

        set<int> st;
        vector<int> C;

        for(int i=0;i<A.size();i++){

            st.insert(A[i]);
            int cnt=0;
            for(int j=0;j<=i;j++){
                if(st.count(B[j]) ) cnt++;
            }
            C.push_back(cnt);
        }
        return C;
    }
};