class RandomizedSet {
public:
    vector<int> arr;
    // num, idx            
    unordered_map<int,int> idxMap;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(idxMap.count(val)) return false;
        
        idxMap[val]=arr.size();
        arr.push_back(val); 
        
        return true;
    }
    
    bool remove(int val) {
        //imp logic
        if(!idxMap.count(val)) return false;
        // get idx, and last el 
        int idx=idxMap[val];
        int lastEl=arr.back();
        // swap elementToBeDeleted with lastEl 
        arr[idx]=lastEl;
        idxMap[lastEl]=idx;

        // pop the el to eb removed from the back
        arr.pop_back();

        //update map 
        idxMap.erase(val);
        return true;
    }
    
    int getRandom() {
        // was retuning index
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */