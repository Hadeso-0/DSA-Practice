class MyHashSet {
    vector<bool> cont;
public:
    MyHashSet() {
        cont.resize(1000001);
    }
    
    void add(int key) {
        cont[key] = true;
    }
    
    void remove(int key) {
        cont[key] = false;
    }
    
    bool contains(int key) {
        return cont[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */