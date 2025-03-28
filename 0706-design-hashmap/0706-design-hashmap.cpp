class MyHashMap {
public:
    vector<long long> arr;

    MyHashMap() {
        arr.resize(1000001, -1);  // Resize the vector to 1,000,000 elements, each initialized to -1
    }

    void put(int key, int value) {
        arr[key]=value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */