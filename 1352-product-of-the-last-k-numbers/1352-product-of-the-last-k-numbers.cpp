class ProductOfNumbers {
public:
    vector<int> st;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        st.push_back(num);
    }
    
    int getProduct(int k) {
        int start = st.size() - k;
        int end = st.size() - 1;
        
        
        int ans = 1;
        for (int i = end; i >= start; i--) {
            if (st[i] == 0) {
                return 0;
            }
            ans *= st[i];
        }
        return ans;
    }
};