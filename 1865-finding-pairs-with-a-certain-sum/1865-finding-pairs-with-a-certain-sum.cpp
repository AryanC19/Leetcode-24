class FindSumPairs {
public:
    vector<int> arr1,arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;
    }
    
    void add(int index, int val) {
        arr2[index]+=val;
    }
        
    int count(int tot) {
        int cnt = 0;
        unordered_map<int, int> freq;
        for (int j : arr2) freq[j]++;

        for (int i : arr1) {
            cnt += freq[tot - i];
        }

        return cnt;
    }

};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */