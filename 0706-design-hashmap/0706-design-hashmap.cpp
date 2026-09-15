class MyHashMap {
public:
    vector<pair<int,int>> mp;
    void put(int key, int value) {
        for(auto& [k,v]: mp){
            if(k==key) {
                v = value;
                return;
            }
        }
        mp.push_back({key,value});
    }
    
    int get(int key) {
        for(auto& [k,v]: mp){
            if(k==key) {
                return v;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto& [k,v]: mp){
            if(k==key) {
                v = -1;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */