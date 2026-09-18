class TimeMap {
private:
    unordered_map<
        string, 
        vector<pair<int, string>>
    > mp;  // key->{time, val}
public:
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];
        int l = 0;
        int r = v.size()-1;
        int bestIdx = -1;
        string ans = "";
        while(l<=r){
            int m = l + (r-l)/2;
            int t = v[m].first;
            string val = v[m].second;
            if(t <= timestamp){
                if(m>bestIdx){
                    bestIdx = m;
                    ans = val;
                }
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */