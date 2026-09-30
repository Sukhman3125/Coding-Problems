class Router {
    using t = tuple<int, int, int>;
    struct Hash {
        size_t operator()(const t& x) const {
            auto [a, b, c] = x;

            size_t h1 = hash<int>{}(a);
            size_t h2 = hash<int>{}(b);
            size_t h3 = hash<int>{}(c);

            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

private:
    int memoryLimit;
    deque<t> q;
    unordered_set<t, Hash> st;
    unordered_map<int, vector<int>> timestamps;

public:
    Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        t curr = {source, destination, timestamp};
        if (st.contains(curr))
            return false;
        st.insert(curr);
        if (q.size() == memoryLimit)
            forwardPacket();
        q.push_back(curr);
        timestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};
        auto [s, d, time] = q.front();
        q.pop_front();
        st.erase({s, d, time});
        timestamps[d].erase(timestamps[d].begin());
        return {s, d, time};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!timestamps.contains(destination))
            return 0;
        auto& v = timestamps[destination];
        auto l = lower_bound(v.begin(), v.end(), startTime);
        auto r = upper_bound(v.begin(), v.end(), endTime);

        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */