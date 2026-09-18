class RandomizedSet {
private:
    vector<int> st;
    unordered_map<int,int> idxOf;
public:
    bool insert(int val) {
        if(idxOf.contains(val)) return false;
        st.push_back(val);
        idxOf[val] = st.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!idxOf.contains(val)) return false;
        int idx = idxOf[val];
        int swapVal = st.back();
        swap(st[idx], st.back());
        st.pop_back();
        idxOf[swapVal] = idx;
        idxOf.erase(val);
        return true;
    }
    
    int getRandom() {
        int i = rand()%st.size();
        return st[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */