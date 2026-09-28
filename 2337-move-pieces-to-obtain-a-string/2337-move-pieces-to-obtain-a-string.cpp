class Solution {
public:
    bool canChange(string s, string t) {
        vector<pair<char, int>> idx1;
        vector<pair<char, int>> idx2;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '_')
                idx1.push_back({s[i], i});
            if (t[i] != '_')
                idx2.push_back({t[i], i});
        }
        if (idx1.size() != idx2.size())
            return false;
        n = idx1.size();
        for (int i = 0; i < n; i++) {
            auto [c1, i1] = idx1[i];
            auto [c2, i2] = idx2[i];
            if(c1!=c2) return false;
            if(c1=='L' && i1<i2) return false;
            if(c1=='R' && i1>i2) return false;
        }
        return true;
    }
};