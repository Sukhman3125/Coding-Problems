class MyHashSet {
public:
    vector<int> s;    
    void add(int key) {
        s.push_back(key);
    }
    
    void remove(int key) {
        for(auto& it:s){
            if(it==key) it = -1;
        }
    }
    
    bool contains(int key) {
        for(auto it:s){
            if(it==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */