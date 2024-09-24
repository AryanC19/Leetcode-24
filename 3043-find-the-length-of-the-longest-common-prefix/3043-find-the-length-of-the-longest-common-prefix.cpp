class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(auto i:arr1){

            while(i>10){
                if(!st.count(i) && i>0){
                    st.insert(i);
                    i=i/10;
                }
            }
        }

        int result=0;
        for(auto i:arr2){
            while(i>0){
                if(st.count(i)){
                    result=max(result, static_cast<int>(log10(i))+1);
                }
                i/=10;
            }
        }
        
        return result;
    }
};